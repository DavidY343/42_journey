#include "../../includes/network/Server.hpp"
#include "../../includes/network/Client.hpp"
#include <cstring>
#include <iostream>
#include <fcntl.h> 
#include <map>
#include <algorithm>
#include <arpa/inet.h>
#include <netdb.h>

Server::Server(int port, const std::string& password) : _port(port), _password(password), _serverSocket(-1), _parser(new Parser(this))
{
	setupSocket();
}

Server::~Server()
{
    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        shutdown(it->first, SHUT_RDWR);
        close(it->first);
        std::cout << "Closed connection for client FD: " << it->first << std::endl;
    }
    _clients.clear();
    for (std::map<std::string, Channel*>::iterator it = _channels.begin(); 
         it != _channels.end(); ++it)
    {
        delete it->second;
        std::cout << "Deleted channel: " << it->first << std::endl;
    }
    _channels.clear();
    _pollFds.clear();

    if (_serverSocket >= 0)
    {
        shutdown(_serverSocket, SHUT_RDWR);
        close(_serverSocket);
        std::cout << "Server socket closed" << std::endl;
    }
    delete _parser;
    _parser = NULL;

    std::cout << "Server shutdown complete" << std::endl;
}

void Server::setupSocket()
{
    // Crea un socket TCP/IP.
    // Lo configura como no bloqueante.
    // Permite reutilizar la dirección.
    // Asigna IP y puerto.
    // Lo enlaza (bind) y pone en escucha (listen).
    // Prepara poll() para monitorizar conexiones entrantes.

	_serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (_serverSocket < 0)
		throw std::runtime_error("Failed to create socket");

	fcntl(_serverSocket, F_SETFL, O_NONBLOCK);

	int opt = 1;
	if (setsockopt(_serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
		throw std::runtime_error("setsockopt() failed");

	std::memset(&_serverAddr, 0, sizeof(_serverAddr));
	_serverAddr.sin_family = AF_INET;
	_serverAddr.sin_addr.s_addr = INADDR_ANY;
	_serverAddr.sin_port = htons(_port);

	if (bind(_serverSocket, (struct sockaddr*)&_serverAddr, sizeof(_serverAddr)) < 0)
		throw std::runtime_error("Bind failed");

	if (listen(_serverSocket, 10) < 0)
		throw std::runtime_error("Listen failed");

	struct pollfd pfd;
	pfd.fd = _serverSocket;
	pfd.events = POLLIN;
    pfd.revents = 0;
	_pollFds.push_back(pfd);

	std::cout << "IRC Server started on port " << _port << std::endl;
}

void Server::run()
{
    // Espera con poll() hasta que haya actividad en algún socket.
    // Distribuye el trabajo:
    // Si es el socket del servidor, acepta nueva conexión.
    // Si es un socket de cliente, lee y procesa sus datos.
    // Repite el proceso.

	while (true)
    {
		int ret = poll(&_pollFds[0], _pollFds.size(), -1);
		if (ret < 0)
			throw std::runtime_error("poll() failed");

		for (size_t i = 0; i < _pollFds.size(); ++i)
        {
			if (_pollFds[i].revents & POLLIN)
            {
				if (_pollFds[i].fd == _serverSocket)
                {
					acceptNewConnection();
                }
				else
					handleClientData(_pollFds[i].fd);
			}
		}
	}
}

void Server::acceptNewConnection()
{
	struct sockaddr_in clientAddr;
	socklen_t addrLen = sizeof(clientAddr);
	int clientFd = accept(_serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
	if (clientFd < 0)
    {
		std::cerr << "Failed to accept new connection" << std::endl;
		return;
	}

	fcntl(clientFd, F_SETFL, O_NONBLOCK);

	struct pollfd pfd;
	pfd.fd = clientFd;
	pfd.events = POLLIN;
    pfd.revents = 0;
	_pollFds.push_back(pfd);


	char hostname[NI_MAXHOST];
    int res = getnameinfo((struct sockaddr *) &clientAddr, sizeof(clientAddr), hostname, NI_MAXHOST, NULL, 0, NI_NUMERICSERV);
    if (res != 0)
	{
        throw std::runtime_error("Error while getting a hostname on a new client!");
	}
	_clients[clientFd] = Client(clientFd, hostname);
	std::cout << "New client connected: FD " << clientFd << std::endl;
}


void Server::handleClientData(int clientFd)
{
    static std::map<int, std::string> clientBuffers;
    
    char buffer[512];
    ssize_t bytesRead = recv(clientFd, buffer, sizeof(buffer) - 1, 0);

    if (bytesRead <= 0)
    {
        forceClientQuit(clientFd, "Connection closed or error");
        return;
    }

    buffer[bytesRead] = '\0';
    clientBuffers[clientFd] += buffer;

    size_t newline_pos;
    while ((newline_pos = clientBuffers[clientFd].find('\n')) != std::string::npos)
    {
        std::string message = clientBuffers[clientFd].substr(0, newline_pos + 1);
        clientBuffers[clientFd].erase(0, newline_pos + 1);
        
        std::string::iterator end_pos = std::remove(message.begin(), message.end(), '\r');
        message.erase(end_pos, message.end());
        
        //std::cout << "Received from " << clientFd << ": " << message;

		try
		{
			Client& client = _clients.at(clientFd);
			_parser->main(&client, message);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error processing command from client " << clientFd 
						<< ": " << e.what() << std::endl;
		}
    }


    if (clientBuffers[clientFd].size() > 4096)
    {
        std::cerr << "Client " << clientFd << " buffer overflow" << std::endl;
        std::cerr << "Disconnecting" << std::endl;
        forceClientQuit(clientFd, "Buffer overflow");
    }
}

void Server::forceClientQuit(int clientFd, const std::string& reason) {
    if (_clients.find(clientFd) == _clients.end()) return;

    Client* client = &_clients[clientFd];
    std::string quitMsg = ":" + client->getNickname() + " QUIT :" + reason + "\r\n";


    std::vector<std::string> channelNames = this->getChannels();

    for (std::vector<std::string>::iterator it = channelNames.begin(); it != channelNames.end(); ++it) {
        Channel* channel = this->getChannel(*it);
        if (channel && channel->hasClient(client)) {
            channel->broadcast(quitMsg, client);
            channel->removeOperator(client);
            channel->removeInvite(client);
            channel->removeClient(client);

            if (channel->isEmpty())
                this->removeChannel(*it);
        }
    }

    client->sendMessage(quitMsg);
    this->disconnectClient(client->getFd());
}

void Server::disconnectClient(int clientFd)
{
    if (_clients.find(clientFd) == _clients.end()) return;
	close(clientFd);
	for (size_t i = 0; i < _pollFds.size(); ++i)
    {
		if (_pollFds[i].fd == clientFd)
        {
			_pollFds.erase(_pollFds.begin() + i);
			break;
		}
	}
	_clients.erase(clientFd);
	std::cout << "Client with fd: " << clientFd << " disconnected" << std::endl;
}


std::string Server::getPassword() {
    return _password;
}

bool Server::isNicknameTaken(const std::string& newNick)
{
    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if (it->second.getNickname() == newNick)
            return true;
    }
    return false;
}

Client* Server::getClientByNick(const std::string& nick) {
    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if (it->second.getNickname() == nick)
            return &it->second;
    }
    return NULL;
}

Channel* Server::getChannel(const std::string& channelName) {
    std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
    if (it != _channels.end())
        return it->second;
    return NULL;
}

std::vector<std::string> Server::getChannels() const {
    std::vector<std::string> channelNames;
    for (std::map<std::string, Channel*>::const_iterator it = _channels.begin(); it != _channels.end(); ++it) {
        channelNames.push_back(it->first);
    }
    return channelNames;
}

Channel* Server::createChannel(const std::string& channelName) {
    Channel* channel = new Channel(channelName);
    _channels[channelName] = channel;
    return channel;
}

void Server::removeChannel(const std::string& channelName) {
    std::map<std::string, Channel*>::iterator it = _channels.find(channelName);
    if (it != _channels.end()) {
        delete it->second;
        _channels.erase(it);
    }
}
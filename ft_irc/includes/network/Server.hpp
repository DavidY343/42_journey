#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <map>
#include <poll.h>
#include <netinet/in.h>
#include <unistd.h> 
#include <stdexcept>
#include <sys/socket.h>

#include "../commands/Parser.hpp"
#include "../network/Client.hpp"
#include "../network/Channel.hpp"

class Parser;

class Server
{
    public:
        Server(int port, const std::string& password);
        ~Server();

        void run();
        void disconnectClient(int clientFd);


        std::string getPassword();
        bool isNicknameTaken(const std::string& newNick);
        Client* getClientByNick(const std::string& nick);
        Channel* getChannel(const std::string& channelName);
        std::vector<std::string> getChannels() const;
        Channel* createChannel(const std::string& channelName);
        void removeChannel(const std::string& channelName);
        void forceClientQuit(int clientFd, const std::string& reason);

    private:
        int _port;
        std::string _password;

        int _serverSocket;
        struct sockaddr_in _serverAddr;

        std::vector<struct pollfd> _pollFds;
        std::map<int, Client> _clients;
        std::map<std::string, Channel*> _channels;
        Parser*                 _parser;
        
        void setupSocket();
        void acceptNewConnection();
        void handleClientData(int clientFd);
};

#endif

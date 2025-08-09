#include "../../includes/network/Client.hpp"

Client::Client(int fd, const std::string &hostname) : _fd(fd), _hostname(hostname), _registered(false), _authenticated(false) {}

Client::Client() : _fd(-1), _hostname(""), _registered(false), _authenticated(false) {}

Client::~Client() {}

int Client::getFd() const {
    return _fd;
}

const std::string& Client::getNickname() const {
    return _nickname;
}

const std::string& Client::getUsername() const {
    return _username;   
}


const std::string& Client::getHostname() const {
    return _hostname;
}

const std::string& Client::getInputBuffer() const {
    return _inputBuffer;
}

void Client::setNickname(const std::string& nickname) {
    _nickname = nickname;
}

void Client::setUsername(const std::string& username) {
    _username = username;
}


void Client::setHostname(const std::string& hostname) {
    _hostname = hostname;
}

void Client::appendToBuffer(const std::string& data) {
    _inputBuffer += data;
}

void Client::clearBuffer() {
    _inputBuffer.clear();
}

bool Client::isRegistered() const {
    return _registered;
}

void Client::setRegistered(bool value) {
    _registered = value;
}

bool Client::isAuthenticated() const {
    return _authenticated;
}

void Client::setAuthenticated(bool value) {
    _authenticated = value;
}

void Client::sendMessage(const std::string& msg)
{
    std::string toSend = msg;
    if (msg.find("\r\n") == std::string::npos)
        toSend += "\r\n";
    send(_fd, toSend.c_str(), toSend.length(), 0);
}

std::string Client::getPrefix() {
    return _nickname + "!" + _username + "@" + _hostname;
}


void Client::Welcome()
{
    if (isAuthenticated() && !_nickname.empty() && !_username.empty())
    {
        setRegistered(true);
        sendMessage("Welcome to the IRC server, " + getPrefix());
    }
}

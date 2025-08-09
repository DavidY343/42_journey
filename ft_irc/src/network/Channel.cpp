#include "../../includes/network/Channel.hpp"

Channel::Channel(const std::string& name) : _name(name), _userLimit(-1) {}

Channel::~Channel()
{
    _clients.clear();
    _operators.clear();
    _invited.clear();
    _modes.clear();
}

bool Channel::hasClient(Client* client) {
    return std::find(_clients.begin(), _clients.end(), client) != _clients.end();
}

void Channel::addClient(Client* client) {
    if (!hasClient(client))
        _clients.push_back(client);
}

void Channel::removeClient(Client* client) {
    _clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
}

bool Channel::isEmpty() {
    return _clients.empty();
}

void Channel::broadcast(const std::string& msg) {
    for (size_t i = 0; i < _clients.size(); ++i) {
        _clients[i]->sendMessage(msg);
    }
}

void Channel::broadcast(const std::string& msg, Client* sender) {
    for (size_t i = 0; i < _clients.size(); ++i) {
        if (_clients[i] != sender)
            _clients[i]->sendMessage(msg);
    }
}

std::string Channel::getTopic() {
    return _topic;
}

std::string Channel::getNamesList() {
    std::string names;
    for (size_t i = 0; i < _clients.size(); ++i) {
        if (i > 0) names += " ";
        names += _clients[i]->getNickname();
    }
    return names;
}

bool Channel::isModeSet(char c) {
    return _modes.count(c);
}

void Channel::setMode(char c) {
    _modes.insert(c);
}

void Channel::unsetMode(char c) {
    _modes.erase(c);
}

std::string Channel::getModesString() {
    std::string str = "+";
    for (std::set<char>::iterator it = _modes.begin(); it != _modes.end(); ++it)
        str += *it;
    return str;
}

void Channel::setKey(const std::string& key) {
    _key = key;
}

std::string Channel::getKey() {
    return _key;
}

void Channel::clearKey() {
    _key.clear();
}

void Channel::setLimit(int limit) {
    _userLimit = limit;
}

int Channel::getLimit(){
    return _userLimit;
}

void Channel::addOperator(Client* client) {
    _operators.insert(client);
}

void Channel::removeOperator(Client* client) {
    _operators.erase(client);
}

bool Channel::isOperator(Client* client) {
    return _operators.count(client);
}

void Channel::addInvite(Client* client) {
    _invited.insert(client);
}

bool Channel::isInvited(Client* client) {
    return _invited.count(client);
}

void Channel::removeInvite(Client* client) {
    _invited.erase(client);
}

void Channel::setTopic(const std::string& topic) {
	_topic = topic;
}

void Channel::clearLimit() {
	_userLimit = -1;
}

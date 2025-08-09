#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "../network/Client.hpp"

class Channel {
private:
	std::string _name;
	std::string _topic;
	std::string _key;
	int _userLimit;

	std::vector<Client*> _clients;
	std::set<Client*> _operators;
	std::set<Client*> _invited;
	std::set<char> _modes;

public:
	Channel(const std::string& name);

	~Channel();
	
	bool hasClient(Client* client);
	void addClient(Client* client);
	void removeClient(Client* client);
	bool isEmpty();

	void broadcast(const std::string& msg);
	void broadcast(const std::string& msg, Client* sender);

	std::string getTopic();
	std::string getNamesList();

	bool isModeSet(char c);
	void setMode(char c);
	std::string getKey();
	void unsetMode(char c);
	std::string getModesString();

	void setKey(const std::string& key);
	void clearKey();

	void setLimit(int limit);
	int getLimit();

	void addOperator(Client* client);
	void removeOperator(Client* client);
	bool isOperator(Client* client);

	void addInvite(Client* client);
	bool isInvited(Client* client);
	void removeInvite(Client* client);
	
	void setTopic(const std::string& topic);
	void clearLimit();
};

#endif

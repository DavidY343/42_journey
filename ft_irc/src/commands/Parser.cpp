/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:05:08 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 14:01:40 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Parser.hpp"

Parser::Parser(Server* srv) : _srv(srv)
{
    // Authentication
    _commands["PASS"] = new Pass(_srv, false);    // Set password for connection
    _commands["NICK"] = new Nick(_srv, false);    // Set client's nickname
    _commands["USER"] = new User(_srv, false);    // Set username and real name

    // Connection maintenance and disconnection
    _commands["QUIT"] = new Quit(_srv, false);    // Client disconnects from server

    // Channel communication
    _commands["JOIN"] = new Join(_srv);           // Join a channel
    _commands["PART"] = new Part(_srv);           // Leave a channel
    _commands["PRIVMSG"] = new PrivMsg(_srv);     // Send a private or channel message

    // Channel configuration
    _commands["TOPIC"] = new Topic(_srv);         // Set or get channel topic
    _commands["MODE"] = new Mode(_srv);           // Set or get channel/user modes

    // Moderation
    _commands["KICK"] = new Kick(_srv);           // Remove a user from a channel
    _commands["INVITE"] = new Invite(_srv);       // Invite a user to a channel

    // Help
    _commands["HELP"] = new Help(_srv);

}

Parser::~Parser()
{
    std::map<std::string, Command*>::iterator it = _commands.begin();
    while (it != _commands.end())
    {
        delete it->second;
        ++it;
    }
}

std::string Parser::trim(const std::string& str)
{
    const std::string spaces = " \n\r\t\f\v";
    size_t start = str.find_first_not_of(spaces);
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(spaces);
    return str.substr(start, end - start + 1);
}

void Parser::parseLine(const std::string& line, std::string& cmdName, std::vector<std::string>& args)
{
    std::string trimmed = trim(line);
    std::stringstream ss(trimmed);

    if (!(ss >> cmdName))
        return;

    std::string word;
    while (ss >> word)
        args.push_back(word);
}

void Parser::main(Client* client, const std::string& message)
{
    std::stringstream wordStream(message);
    std::string line;

    while (std::getline(wordStream, line))
    {
        std::string commandName;
        std::vector<std::string> args;

        parseLine(line, commandName, args);

        if (commandName.empty())
            continue;

        std::map<std::string, Command*>::iterator it = _commands.find(commandName);
        if (it == _commands.end())
        {
            std::string err = commandName + " :Unknown command\r\n";
            client->sendMessage(err);
            
            std::map<std::string, Command*>::iterator helpIt = _commands.find("HELP");
            std::vector<std::string> emptyArgs;
            helpIt->second->execute(client, emptyArgs);
            continue;
        }

        Command* cmd = it->second;

        if (!client->isRegistered() && cmd->auth_required())
        {
            std::string err = client->getNickname() + " :You have not registered\r\n";
            client->sendMessage(err);
            continue;
        }

        try
        {
            cmd->execute(client, args);
        }
        catch (...)
        {
            std::string err = client->getNickname() + " :Internal server error\r\n";
            client->sendMessage(err);

            std::cerr << "Error: Exception caught while executing command '" 
                      << commandName << "' for client " << client->getNickname() << std::endl;
        }
    }
}

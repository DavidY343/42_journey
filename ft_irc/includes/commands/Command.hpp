/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:09:10 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:52:07 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <string>
#include <sstream>

class Server;
class Client;

#include "../network/Server.hpp"
#include "../network/Client.hpp"

class Command {
protected:
    Server* _srv;
    bool _authRequired;

public:
    Command(Server* srv, bool authRequired);
    virtual ~Command();

    virtual void execute(Client* client, const std::vector<std::string>& args) = 0;
    bool auth_required() const;
};

// Authentication

class Pass : public Command {
public:
    Pass(Server* srv, bool authRequired = false);
    virtual ~Pass();
    void execute(Client* client, const std::vector<std::string>& args);
};

class Nick : public Command {
public:
    Nick(Server* srv, bool authRequired = false);
    virtual ~Nick();

    void execute(Client* client, const std::vector<std::string>& args);
};

class User : public Command
{
public:
    User(Server* srv, bool authRequired = false);
    virtual ~User();

    virtual void execute(Client* client, const std::vector<std::string>& args);
};

// Connection

class Quit : public Command {
public:
    Quit(Server* server, bool authRequired = false);
    ~Quit();

    void execute(Client* client, const std::vector<std::string>& args);
};

// Connection maintenance and disconnection

class Join : public Command {
public:
    Join(Server* srv);
    virtual ~Join();

    virtual void execute(Client* client, const std::vector<std::string>& args);
};

class Part : public Command {
public:
    Part(Server* server);
    virtual ~Part();

    virtual void execute(Client* client, const std::vector<std::string>& args);
};

class PrivMsg : public Command {
public:
    PrivMsg(Server* server);
    ~PrivMsg();
    void execute(Client* client, const std::vector<std::string>& args);
};

// Channel configuration

class Topic : public Command {
public:
    Topic(Server* srv);
    virtual ~Topic();
    void execute(Client* client, const std::vector<std::string>& args);
};

class Mode : public Command {
public:
    Mode(Server* srv);
    virtual ~Mode();

    void execute(Client* client, const std::vector<std::string>& args);
};

// Moderation

class Kick : public Command {
public:
    Kick(Server* server);
    ~Kick();

    void execute(Client* client, const std::vector<std::string>& args);
};

class Invite : public Command {
public:
    Invite(Server* server);
    ~Invite();

    void execute(Client* client, const std::vector<std::string>& args);
};

class Help : public Command {
public:
    Help(Server* srv);
    virtual ~Help();

    virtual void execute(Client* client, const std::vector<std::string>& args);
};

#endif
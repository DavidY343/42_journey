/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:30:16 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/23 14:30:43 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Help::Help(Server* srv) : Command(srv, false) {}

Help::~Help() {}

void Help::execute(Client* client, const std::vector<std::string>& args) {
    (void)args;

    client->sendMessage("NICK <nickname> : Set your nickname\r\n");
    client->sendMessage("USER <user> : Set your username\r\n");
    client->sendMessage("PASS <password> : Set your password\r\n");
    client->sendMessage("JOIN <#channel> [password] : Join or create a channel\r\n");
    client->sendMessage("PART <#channel> : Leave a channel\r\n");
    client->sendMessage("PRIVMSG <target(#channel/nickname)> <text> : Send private message\r\n");
    client->sendMessage("MODE <#channel> <+it> : Manage channel modes\r\n");
    client->sendMessage("MODE <#channel> <+k> <password> : Manage channel modes\r\n");
    client->sendMessage("MODE <#channel> <+l> <limit> : Manage channel modes\r\n");
    client->sendMessage("MODE <#channel> <+o> <nick> : Manage channel modes\r\n");
    client->sendMessage("TOPIC <#channel> [topic] : Set or view channel topic\r\n");
    client->sendMessage("INVITE <nick> <#channel> : Invite a user to a channel\r\n");
    client->sendMessage("KICK <#channel> <user> : Kick user from channel\r\n");
    client->sendMessage("QUIT [reason] : Client Quit\r\n");
    client->sendMessage("HELP : Show this help message\r\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivMsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:07:59 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:56:47 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

PrivMsg::PrivMsg(Server* server) : Command(server, true) {}
PrivMsg::~PrivMsg() {}

void PrivMsg::execute(Client* client, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        client->sendMessage("PRIVMSG <target(#channel/nickname)> <text>: No recipient given\r\n");
        return;
    }

    const std::string& target = args[0];
    std::string message;
    for (size_t i = 1; i < args.size(); ++i) {
        message += args[i];
        if (i != args.size() - 1)
            message += " ";
    }

    if (message.empty()) {
        client->sendMessage("PRIVMSG <target(#channel/nickname)> <text> :No text to send\r\n");
        return;
    }

    if (target[0] == '#') {

        Channel* channel = _srv->getChannel(target);
        if (!channel) {
            client->sendMessage(target + " :No such channel\r\n"); 
            return;
        }

        if (!channel->hasClient(client)) {
            client->sendMessage(target + " :Cannot send to channel\r\n");
            return;
        }

        channel->broadcast(client->getNickname() + " PRIVMSG " + target + " :" + message + "\r\n", client);
    } else {

        Client* receiver = _srv->getClientByNick(target);
        if (!receiver) {
            client->sendMessage(target + " :No such nick/channel\r\n");
            return;
        }

        receiver->sendMessage(client->getNickname() + " PRIVMSG " + target + " :" + message + "\r\n");
    }
}
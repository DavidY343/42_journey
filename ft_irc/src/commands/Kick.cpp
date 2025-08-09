/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:41:43 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:59:31 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Kick::Kick(Server* srv) : Command(srv, true) {}

Kick::~Kick() {}

void Kick::execute(Client* client, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        client->sendMessage("KICK <#channel> <user> :Not enough parameters\r\n");
        return;
    }

    const std::string& channelName = args[0];
    const std::string& targetNick = args[1];

    Channel* channel = _srv->getChannel(channelName);
    if (!channel) {
        client->sendMessage(channelName + " :No such channel\r\n");
        return;
    }

    if (!channel->hasClient(client)) {
        client->sendMessage(channelName + " :You're not on that channel\r\n");
        return;
    }

    if (!channel->isOperator(client)) {
        client->sendMessage(channelName + " :You're not channel operator\r\n");
        return;
    }

    Client* targetClient = _srv->getClientByNick(targetNick);
    if (!targetClient || !channel->hasClient(targetClient)) {
        client->sendMessage(targetNick + " " + channelName + " :They aren't on that channel\r\n");
        return;
    }

    std::string reason = (args.size() > 2) ? args[2] : client->getNickname();
    
    channel->broadcast(client->getNickname() + " KICK " + channelName + " " + targetNick + " :" + reason + "\r\n");
    
    channel->removeOperator(client);
    channel->removeInvite(client);
    channel->removeClient(targetClient);
}

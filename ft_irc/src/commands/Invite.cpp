/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:45:18 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:59:17 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Invite::Invite(Server* server) : Command(server, true) {}
Invite::~Invite() {}

void Invite::execute(Client* client, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        client->sendMessage("INVITE <nick> <#channel> :Not enough parameters\r\n");
        return;
    }

    const std::string& nickname = args[0];
    const std::string& channelName = args[1];

    Client* targetClient = _srv->getClientByNick(nickname);
    if (!targetClient) {
        client->sendMessage(nickname + " :No such nick/channel\r\n");
        return;
    }

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

    if (channel->hasClient(targetClient)) {
        client->sendMessage(nickname + " :is already used on channel " + channelName + "\r\n");
        return;
    }

    channel->addInvite(targetClient);
    client->sendMessage(client->getNickname() + " " + nickname + " " + channelName + "\r\n");
    targetClient->sendMessage(client->getNickname() + " INVITE " + nickname + " to " + channelName + "\r\n");
}
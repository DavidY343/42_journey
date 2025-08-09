/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:49:47 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:56:23 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Parser.hpp"

Part::Part(Server* server) : Command(server, true) {}

Part::~Part() {}

void Part::execute(Client* client, const std::vector<std::string>& args) {
    if (args.empty()) {
        client->sendMessage("PART <#channel> :Not enough parameters\r\n");
        return;
    }

    std::string channelName = args[0];
    Channel* channel = _srv->getChannel(channelName);

    if (!channel) {
        client->sendMessage(channelName + " :No such channel\r\n");
        return;
    }

    if (!channel->hasClient(client)) {
        client->sendMessage(channelName + " :You're not on that channel\r\n");
        return;
    }

    channel->broadcast(client->getPrefix() + " PART " + channelName + "\r\n");

    channel->removeOperator(client);
    channel->removeInvite(client);
    channel->removeClient(client);

    if (channel->isEmpty()) {
        _srv->removeChannel(channelName);
    }
}
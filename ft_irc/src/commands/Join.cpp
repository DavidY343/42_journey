/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:08:59 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/23 14:41:52 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"


Join::Join(Server* srv) : Command(srv, true) {}
Join::~Join() {}

void Join::execute(Client* client, const std::vector<std::string>& args) {
    if (args.empty()) {
        client->sendMessage("JOIN <#channel> [password] :Not enough parameters\r\n");
        return;
    }

    std::stringstream ss(args[0]);
    std::string channelName;

    while (std::getline(ss, channelName, ',')) {
        if (channelName.empty() || channelName[0] != '#') {
            client->sendMessage(channelName + " :Invalid channel name\r\n");
            continue;
        }

        Channel* channel = _srv->getChannel(channelName);

        if (!channel)
        {
            channel = _srv->createChannel(channelName);
            channel->addOperator(client);
        }

        if (channel->isModeSet('k')) {
            if (args.size() < 2) {
                client->sendMessage(channelName + " :Cannot join channel (+k), key required\r\n");
                continue;
            }
            std::string providedKey = args[1];
            if (providedKey != channel->getKey()) {
                client->sendMessage(channelName + " :Cannot join channel (+k)\r\n");
                continue;
            }
        }

        if (channel->isModeSet('l') && channel->getNamesList().size() >= (size_t)channel->getLimit()) {
            if (args.size() < 2) {
                client->sendMessage(channelName + " :Cannot join channel (+l), key required\r\n");
                continue;
            }
            client->sendMessage(channelName + " :Cannot join channel (+l)\r\n");
            continue;
        }

        if (channel->isModeSet('i') && !channel->isInvited(client)) {
            if (args.size() < 2) {
                client->sendMessage(channelName + " :Cannot join channel (+i), key required\r\n");
                continue;
            }
            client->sendMessage(channelName + " :Cannot join channel (+i)\r\n");
            continue;
        }

        if (!channel->hasClient(client))
        {
            channel->addClient(client);

            channel->broadcast(client->getNickname() + " JOIN " + channelName + "\r\n");

            std::string names = channel->getNamesList();
            client->sendMessage("The channel " + channelName + " has the following participants : " + names + "\r\n");
        }
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:57:30 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 15:57:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"


Quit::Quit(Server* server, bool authRequired) : Command(server, authRequired) {}
Quit::~Quit() {}

void Quit::execute(Client* client, const std::vector<std::string>& args) {
    std::string reason = "Client Quit";
    if (!args.empty())
        reason = args[0];

    std::string quitMsg = client->getNickname() + " QUIT :" + reason + "\r\n";

    std::vector<std::string> channelNames = _srv->getChannels();

    for (std::vector<std::string>::iterator it = channelNames.begin(); it != channelNames.end(); ++it) {
        Channel* channel = _srv->getChannel(*it);
        if (channel && channel->hasClient(client)) {
            channel->broadcast(quitMsg, client);
            channel->removeOperator(client);
            channel->removeInvite(client);
            channel->removeClient(client);

            if (channel->isEmpty())
                _srv->removeChannel(*it);
        }
    }

    client->sendMessage(quitMsg);
    _srv->disconnectClient(client->getFd());
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:24:58 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:59:00 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Topic::Topic(Server* srv) : Command(srv, true) {}

Topic::~Topic() {}

void Topic::execute(Client* client, const std::vector<std::string>& args) {
    if (args.empty()) {
        client->sendMessage("TOPIC <#channel> [topic] :Not enough parameters\r\n");
        return;
    }

    const std::string& channelName = args[0];
    Channel* channel = _srv->getChannel(channelName);

    if (!channel) {
        client->sendMessage(channelName + " :No such channel\r\n");
        return;
    }

    if (!channel->hasClient(client)) {
        client->sendMessage(channelName + " :You're not on that channel\r\n");
        return;
    }

    if (args.size() == 1) {
        std::string topic = channel->getTopic();
        if (topic.empty())
            client->sendMessage(channelName + " :No topic is set\r\n");
        else
            client->sendMessage(channelName + " :" + topic + "\r\n");
        return;
    }

    if (channel->isModeSet('t') && !channel->isOperator(client)) {
        client->sendMessage(channelName + " :You're not channel operator\r\n");
        return;
    }

    std::string newTopic;
    for (size_t i = 1; i < args.size(); ++i) {
        newTopic += args[i];
        if (i != args.size() - 1)
            newTopic += " ";
    }

    channel->setTopic(newTopic);

    std::string msg = client->getNickname() + " TOPIC " + channelName + " :" + newTopic + "\r\n";
    channel->broadcast(msg);
}

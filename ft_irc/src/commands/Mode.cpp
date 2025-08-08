/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:42:49 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:58:42 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Mode::Mode(Server* srv) : Command(srv, true) {}

Mode::~Mode() {}

void Mode::execute(Client* client, const std::vector<std::string>& args) {
    if (args.empty()) {
        client->sendMessage("MODE <#channel> <+-itklo> :Not enough parameters\r\n");
        return;
    }

    const std::string& target = args[0];

    Channel* channel = _srv->getChannel(target);
    if (!channel) {
        client->sendMessage(target + " :No such channel\r\n");
        return;
    }

    if (!channel->hasClient(client)) {
        client->sendMessage(target + " :You're not on that channel\r\n");
        return;
    }

    if (args.size() == 1) {
        std::string modes = channel->getModesString();
        std::string topic = channel->getTopic();

        client->sendMessage(client->getNickname() + " " + target + " " + modes + "\r\n");
        client->sendMessage(client->getNickname() + " " + target + " :" + (topic.empty() ? "No topic is set" : topic) + "\r\n");
        return;
    }

    if (!channel->isOperator(client)) {
        client->sendMessage(target + " :You're not channel operator\r\n");
        return;
    }

    std::string modeStr = args[1];
    char mode = modeStr[1];
    bool add = (modeStr[0] == '+');

    if (mode == 'i' || mode == 't') {
        if (add)
            channel->setMode(mode);
        else
            channel->unsetMode(mode);

        channel->broadcast(client->getNickname() + " MODE " + target + " " + modeStr + "\r\n");
    } 
    else if (mode == 'k') {
        if (add) {
            if (args.size() < 3) {
                client->sendMessage("MODE :Not enough parameters\r\n");
                return;
            }
            std::string key = args[2];
            channel->setKey(key);
            channel->setMode('k');
        } else {
            channel->unsetMode('k');
            channel->clearKey();
        }
        channel->broadcast(client->getNickname() + " MODE " + target + " " + modeStr + (add ? " " + args[2] : "") + "\r\n");
    }
    else if (mode == 'l') {
        if (add) {
            if (args.size() < 3) {
                client->sendMessage("MODE :Not enough parameters\r\n");
                return;
            }
            std::istringstream iss(args[2]);
            int limit;
            iss >> limit;
            if (iss.fail()) {
                client->sendMessage("MODE :Invalid limit parameter\r\n");
                return;
            }
            channel->setLimit(limit);
            channel->setMode('l');
        } else {
            channel->unsetMode('l');
            channel->clearLimit();
        }
        channel->broadcast(client->getNickname() + " MODE " + target + " " + modeStr + (add ? " " + args[2] : "") + "\r\n");
    }
    else if (mode == 'o') {
        if (args.size() < 3) {
            client->sendMessage("MODE :Not enough parameters\r\n");
            return;
        }
        Client* targetClient = _srv->getClientByNick(args[2]);
        if (!targetClient || !channel->hasClient(targetClient)) {
            client->sendMessage(args[2] + " " + target + " :They aren't on that channel\r\n");
            return;
        }

        if (add)
            channel->addOperator(targetClient);
        else
            channel->removeOperator(targetClient);

        channel->broadcast(client->getNickname() + " MODE " + target + " " + modeStr + " " + args[2] + "\r\n");
    }
    else {
        client->sendMessage(std::string(1, mode) + " :is unknown mode char to me\r\n");
    }
}
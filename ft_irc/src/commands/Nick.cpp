/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:29:49 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:54:59 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Nick::Nick(Server* srv, bool authRequired) : Command(srv, authRequired) {}

Nick::~Nick() {}

void Nick::execute(Client* client, const std::vector<std::string>& args) {
    if (client->isRegistered()) {
        client->sendMessage("NICK :You may not reregister\r\n");
        return;
    }

    if (args.empty()) {
        client->sendMessage("NICK <nickname> :No nickname given\r\n");
        return;
    }

    std::string newNick = args[0];

    if (_srv->isNicknameTaken(newNick)) {
        client->sendMessage(newNick + " :Nickname is already in use\r\n");
        return;
    }

    client->setNickname(newNick);
    client->Welcome();
}
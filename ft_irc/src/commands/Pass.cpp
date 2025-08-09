/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:15:00 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:55:48 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Pass::Pass(Server* srv, bool authRequired) : Command(srv, authRequired) {}

Pass::~Pass() {}

void Pass::execute(Client* client, const std::vector<std::string>& args) {
    if (client->isRegistered()) {
        client->sendMessage("You may not reregister\r\n");
        return;
    }

    if (args.empty()) {
        client->sendMessage("PASS <password> :Not enough parameters\r\n");
        return;
    }

    const std::string& givenPass = args[0];
    if (givenPass != _srv->getPassword())
    {
        client->sendMessage("Password incorrect\r\n");
        return;
    }
    client->setAuthenticated(true);
    client->Welcome();
}
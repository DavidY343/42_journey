/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:15:00 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/22 13:55:36 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

User::User(Server* srv, bool authRequired) : Command(srv, authRequired) {}

User::~User() {}

void User::execute(Client* client, const std::vector<std::string>& args)
{
    if (args.empty()) {
        client->sendMessage("USER <user> :Not enough parameters\r\n");
        return;
    }

    if (client->isRegistered())
    {
        client->sendMessage("You may not reregister\r\n");
        return;
    }

    client->setUsername(args[0]);

    client->Welcome();

}

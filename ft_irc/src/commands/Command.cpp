/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:00:15 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/18 16:06:36 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/Command.hpp"

Command::Command(Server* srv, bool authRequired)
    : _srv(srv), _authRequired(authRequired) {}

Command::~Command() {}

bool Command::auth_required() const {
    return _authRequired;
}


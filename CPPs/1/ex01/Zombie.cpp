/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:59 by david             #+#    #+#             */
/*   Updated: 2024/10/29 17:26:58 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): _name(name) {}

Zombie::Zombie() {}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string Zombie::getName(void)
{
	return this->_name;
}

Zombie::~Zombie() {
    std::cout << getName() << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
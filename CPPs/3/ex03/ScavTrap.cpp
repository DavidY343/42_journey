/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:24:56 by david             #+#    #+#             */
/*   Updated: 2024/11/12 20:27:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _guardMode(false)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardMode(other._guardMode)
{
    std::cout << "ScavTrap " << _name << " copied!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        _guardMode = other._guardMode;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
	{
        std::cout << "ScavTrap " << _name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
	{
        std::cout << "ScavTrap " << _name << " has no hit points left to attack!" << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " viciously attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    _guardMode = true;
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
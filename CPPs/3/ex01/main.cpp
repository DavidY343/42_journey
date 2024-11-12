/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:26:23 by david             #+#    #+#             */
/*   Updated: 2024/11/12 20:27:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating Robots ===" << std::endl;
    ScavTrap scav("Guardian");
    
    std::cout << "\n=== Testing Actions ===" << std::endl;
    scav.attack("Intruder");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    // ScavTrap has 50 energy points, each action costs 1
    for (int i = 0; i < 48; ++i) {
        scav.attack("Training Dummy");
    }
    // These should fail due to no energy
    scav.attack("Enemy");
    scav.beRepaired(10);
    
    std::cout << "\n=== Testing Destruction ===" << std::endl;
    ScavTrap *dynamicScav = new ScavTrap("Temporary");
    delete dynamicScav; // Should show destruction order
    
    return 0;
}
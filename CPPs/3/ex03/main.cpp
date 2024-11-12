/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:15:21 by david             #+#    #+#             */
/*   Updated: 2024/11/12 21:20:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Creating Robots ===" << std::endl;
    DiamondTrap diamond("Hybrid");
    
    std::cout << "\n=== Testing Actions ===" << std::endl;
    diamond.whoAmI();
    diamond.attack("Enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.guardGate();
    diamond.highFivesGuys();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    // DiamondTrap has ScavTrap's energy points (50)
    for (int i = 0; i < 48; ++i) {
        diamond.attack("Training Dummy");
    }
    // These should fail due to no energy
    diamond.attack("Enemy");
    diamond.beRepaired(10);
    
    std::cout << "\n=== Testing Inheritance Chain ===" << std::endl;
    DiamondTrap *dynamicDiamond = new DiamondTrap("Temporary");
    dynamicDiamond->whoAmI();
    delete dynamicDiamond; // Should show destruction order
    
    return 0;
}
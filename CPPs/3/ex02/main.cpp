/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:15:21 by david             #+#    #+#             */
/*   Updated: 2024/11/12 21:17:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Creating Robots ===" << std::endl;
    FragTrap frag("Destroyer");
    
    std::cout << "\n=== Testing Actions ===" << std::endl;
    frag.attack("Enemy");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    // FragTrap has 100 energy points, each action costs 1
    for (int i = 0; i < 98; ++i) {
        frag.attack("Training Dummy");
    }
    // These should fail due to no energy
    frag.attack("Enemy");
    frag.beRepaired(10);
    
    std::cout << "\n=== Testing Destruction ===" << std::endl;
    FragTrap *dynamicFrag = new FragTrap("Temporary");
    dynamicFrag->highFivesGuys();
    delete dynamicFrag; // Should show destruction order
    
    return 0;
}
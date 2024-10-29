/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:27:12 by david             #+#    #+#             */
/*   Updated: 2024/10/29 19:11:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() 
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return (0);
}

/*int main() {
    // Example 1: Cannot change HumanA's weapon
    {
        Weapon sword("sword");
        Weapon axe("axe");
        
        HumanA knight("Arthur", sword);
        knight.attack();  // Output: "Arthur attacks with their sword"
        
        // Cannot do this - weapon is a reference, it's bound to sword forever:
        // knight.setWeapon(axe);  // This would require a setWeapon method, but it's not possible
        
        // We can only modify the original weapon
        sword.setType("broken sword");
        knight.attack();  // Output: "Arthur attacks with their broken sword"
    }
    
    // Example 2: HumanB can change weapons
    {
        Weapon sword("sword");
        Weapon axe("axe");
        
        HumanB warrior("Bob");
        warrior.setWeapon(sword);
        warrior.attack();  // Output: "Bob attacks with their sword"
        
        // HumanB can change weapons
        warrior.setWeapon(axe);
        warrior.attack();  // Output: "Bob attacks with their axe"
    }
    
    return 0;
}*/
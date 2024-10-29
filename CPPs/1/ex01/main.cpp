/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:02:50 by david             #+#    #+#             */
/*   Updated: 2024/10/29 17:25:09 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int hordeSize;
    Zombie* horde;

    hordeSize = 5;
    std::cout << "Creating a horde of " << hordeSize << " zombies..." << std::endl;
    horde = zombieHorde(hordeSize, "HordeZombie");
    std::cout << "\nZombies announcing themselves:" << std::endl;
    for (int i = 0; i < hordeSize; i++)
    {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    std::cout << "\nDestroying the horde..." << std::endl;
    delete[] horde;
    return (0);
}
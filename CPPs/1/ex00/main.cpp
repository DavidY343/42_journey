/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:02:50 by david             #+#    #+#             */
/*   Updated: 2024/10/29 17:15:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie* heapZombie;

	heapZombie = newZombie("Heap Zombie");
    std::cout << "Creating zombie on stack:" << std::endl;
    randomChump("Stack Zombie");
    
    std::cout << "\nCreating zombie on heap:" << std::endl;
    heapZombie->announce();
    delete heapZombie;
    
    return 0;
}
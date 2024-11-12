/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:53:31 by david             #+#    #+#             */
/*   Updated: 2024/11/12 19:58:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap robot("robot1");
    
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    
    for (int i = 0; i < 9; ++i)
	{
        robot.attack("Enemy");
    }
	
    robot.attack("Enemy");
    
    ClapTrap robot2("robot2");
    robot2.takeDamage(15);

    robot2.attack("Enemy");
    robot2.beRepaired(5);
    
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:18:08 by david             #+#    #+#             */
/*   Updated: 2024/10/29 17:24:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;

    if (N <= 0)
        return (NULL);  
    horde = new Zombie[N];
    for (int i = 0; i < N; i++)
	{
        horde[i].setName(name);
    }
    return (horde);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:30:30 by david             #+#    #+#             */
/*   Updated: 2024/10/29 20:09:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    
    std::cout << "Testing all Harl's complaint levels:" << std::endl;
    std::cout << "=================================" << std::endl << std::endl;
    
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    std::cout << "Testing invalid level:" << std::endl;
    std::cout << "====================" << std::endl << std::endl;
    
    harl.complain("INVALID");
    
    return (0);
}
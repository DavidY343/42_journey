/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:01:03 by david             #+#    #+#             */
/*   Updated: 2025/08/12 02:01:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat alice("Alice", 2);
    Bureaucrat bob("Bob", 80);

    Form contract("Contract", 3, 10);
    Form report("Report", 100, 120);

    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << contract << std::endl;
    std::cout << report << std::endl;

    std::cout << "---- Signing attempts ----" << std::endl;
    alice.signForm(contract); // debería funcionar
    bob.signForm(contract);   // debería fallar

    alice.signForm(report);   // debería funcionar
    bob.signForm(report);     // debería funcionar

    std::cout << "---- Forms status ----" << std::endl;
    std::cout << contract << std::endl;
    std::cout << report << std::endl;

    return 0;
}

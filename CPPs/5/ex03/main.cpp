/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:36:05 by david             #+#    #+#             */
/*   Updated: 2025/08/12 12:36:07 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);        // Máxima autoridad
        Bureaucrat jim("Jim", 140);      // Casi nada de poder
        Bureaucrat tom("Tom", 50);       // Poder intermedio

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << "\n--- Intento de ejecutar sin firmar ---\n";
        bob.executeForm(shrub);

        std::cout << "\n--- Jim intenta firmar Shrubbery (debería fallar) ---\n";
        jim.signForm(shrub);

        std::cout << "\n--- Bob firma Shrubbery ---\n";
        bob.signForm(shrub);

        std::cout << "\n--- Jim intenta ejecutar Shrubbery (debería fallar) ---\n";
        jim.executeForm(shrub);

        std::cout << "\n--- Bob ejecuta Shrubbery ---\n";
        bob.executeForm(shrub);

        std::cout << "\n--- Firmar y ejecutar Robotomy ---\n";
        bob.signForm(robo);
        bob.executeForm(robo);
        bob.executeForm(robo); // Lo ejecuto dos veces para mostrar aleatoriedad

        std::cout << "\n--- Firmar y ejecutar Pardon ---\n";
        bob.signForm(pardon);
        bob.executeForm(pardon);

    } catch (std::exception & e) {
        std::cerr << "Error capturado en main: " << e.what() << std::endl;
    }
    return 0;
}

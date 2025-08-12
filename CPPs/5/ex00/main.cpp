/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:00:36 by david             #+#    #+#             */
/*   Updated: 2025/08/12 02:00:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        std::cout << "Incrementing Alice (should become grade 1)..." << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;

        std::cout << "Incrementing Alice again (should throw)..." << std::endl;
        a.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try
    {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;

        std::cout << "Decrementing Bob (should become 150)..." << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;

        std::cout << "Decrementing Bob again (should throw)..." << std::endl;
        b.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try {
        Bureaucrat bad("Bad", 0);
        (void)bad;
    }
    catch (std::exception & e) {
        std::cout << "Construction test: Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat worse("Worse", 151);
        (void)worse;
    }
    catch (std::exception & e) {
        std::cout << "Construction test: Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

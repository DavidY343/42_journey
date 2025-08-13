/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:56:46 by david             #+#    #+#             */
/*   Updated: 2025/08/13 12:56:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    try {
        std::cout << "=== Test básico ===\n";
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;

        std::cout << "\n=== Test con range ===\n";
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i) vec.push_back(i * 10);
        Span sp2(10);
        sp2.addRange(vec.begin(), vec.end());
        sp2.addNumber(100);
        std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp2.longestSpan() << std::endl;

        std::cout << "\n=== Test con 10000 números ===\n";
        Span bigSpan(10000);
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(std::rand());
        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

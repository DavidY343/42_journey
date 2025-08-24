/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:08:38 by david             #+#    #+#             */
/*   Updated: 2025/08/25 00:18:50 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN <expresion>" << std::endl;
        return 1;
    }

    RPN calculator;
    int result = 0;

    if (calculator.evaluate(argv[1], result)) {
        std::cout << result << std::endl;
        return 0;
    }

    return 1;
}

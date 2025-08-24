/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:08:08 by david             #+#    #+#             */
/*   Updated: 2025/08/25 00:18:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::evaluate(const std::string& expression, int& result) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.size() == 1 && std::string("+-/*").find(token) != std::string::npos) {
            if (_stack.size() < 2) {
                std::cerr << "Error: cannot do operation" << std::endl;
                return false;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            if (token == "+") _stack.push(a + b);
            else if (token == "-") _stack.push(a - b);
            else if (token == "*") _stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    std::cerr << "Error: division by zero" << std::endl;
                    return false;
                }
                _stack.push(a / b);
            }
        } else if (token.size() == 1 && isdigit(token[0])) {

            _stack.push(token[0] - '0');
        } else {
            std::cerr << "Error: not a valid character" << std::endl;
            return false;
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error: not a valid character" << std::endl;
        return false;
    }

    result = _stack.top();
    return true;
}

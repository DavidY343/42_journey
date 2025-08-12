/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:14:36 by david             #+#    #+#             */
/*   Updated: 2025/08/12 13:16:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

namespace
{
    bool isCharLiteral(const std::string &s)
    {
        return s.length() == 1 && !std::isdigit(s[0]) && std::isprint(s[0]);
    }

    bool isIntLiteral(const std::string &s)
    {
        char *end;
        long val = std::strtol(s.c_str(), &end, 10);
        if (*end != '\0')
            return false;
        return val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
    }

    bool isFloatLiteral(const std::string &s)
    {
        if (s == "+inff" || s == "-inff" || s == "nanf")
            return true;
        char *end;
        std::strtof(s.c_str(), &end);
        return (*end == 'f' && *(end + 1) == '\0');
    }

    bool isDoubleLiteral(const std::string &s)
    {
        if (s == "+inf" || s == "-inf" || s == "nan")
            return true;
        char *end;
        std::strtod(s.c_str(), &end);
        return (*end == '\0');
    }

    void printChar(double val)
    {
        if (std::isnan(val) || val < 0 || val > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    }

    void printInt(double val)
    {
        if (std::isnan(val) || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(val) << std::endl;
    }

    void printFloat(double val)
    {
        std::cout << "float: ";
        if (std::isnan(val))
            std::cout << "nanf" << std::endl;
        else if (val == std::numeric_limits<float>::infinity())
            std::cout << "+inff" << std::endl;
        else if (val == -std::numeric_limits<float>::infinity())
            std::cout << "-inff" << std::endl;
        else
        {
            float f = static_cast<float>(val);
            std::cout << std::fixed << std::setprecision((f - static_cast<int>(f) == 0) ? 1 : 6) << f << "f" << std::endl;
        }
    }

    void printDouble(double val)
    {
        std::cout << "double: ";
        if (std::isnan(val))
            std::cout << "nan" << std::endl;
        else if (val == std::numeric_limits<double>::infinity())
            std::cout << "+inf" << std::endl;
        else if (val == -std::numeric_limits<double>::infinity())
            std::cout << "-inf" << std::endl;
        else
            std::cout << std::fixed << std::setprecision((val - static_cast<int>(val) == 0) ? 1 : 6) << val << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    double value = 0.0;

    if (isCharLiteral(literal))
        value = static_cast<double>(literal[0]);
    else if (isIntLiteral(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloatLiteral(literal))
        value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    else if (isDoubleLiteral(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "Invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:36:25 by david             #+#    #+#             */
/*   Updated: 2024/10/29 18:23:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory addresses:" << std::endl;
    std::cout << "str address:\t\t" << &str << std::endl;
    std::cout << "stringPTR address:\t" << stringPTR << std::endl;
    std::cout << "stringREF address:\t" << &stringREF << std::endl;

    std::cout << "\nValues:" << std::endl;
    std::cout << "str value:\t\t" << str << std::endl;
    std::cout << "stringPTR value:\t" << *stringPTR << std::endl;
    std::cout << "stringREF value:\t" << stringREF << std::endl;

    return (0);
}
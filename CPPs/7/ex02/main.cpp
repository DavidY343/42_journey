/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:21:08 by david             #+#    #+#             */
/*   Updated: 2025/08/13 12:27:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#define MAX_VAL 750
int main()
{
	// try
	// {
	// 	std::cout << "=== Array vacío ===" << std::endl;
	// 	Array<int> empty;
	// 	std::cout << "Size: " << empty.size() << std::endl;

	// 	std::cout << "\n=== Array de enteros ===" << std::endl;
	// 	Array<int> numbers(5);
	// 	for (unsigned int i = 0; i < numbers.size(); i++)
	// 		numbers[i] = i * 10;

	// 	for (unsigned int i = 0; i < numbers.size(); i++)
	// 		std::cout << numbers[i] << " ";
	// 	std::cout << std::endl;

	// 	std::cout << "\n=== Copia profunda ===" << std::endl;
	// 	Array<int> copy = numbers;
	// 	copy[0] = 999;

	// 	std::cout << "Original: " << numbers[0] << std::endl;
	// 	std::cout << "Copia: " << copy[0] << std::endl;

	// 	std::cout << "\n=== Array de strings ===" << std::endl;
	// 	Array<std::string> words(3);
	// 	words[0] = "Hola";
	// 	words[1] = "Mundo";
	// 	words[2] = "C++";

	// 	for (unsigned int i = 0; i < words.size(); i++)
	// 		std::cout << words[i] << " ";
	// 	std::cout << std::endl;

	// 	std::cout << "\n=== Acceso fuera de rango ===" << std::endl;
	// 	std::cout << numbers[10] << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << "Excepción: " << e.what() << std::endl;
	// }

	// return 0;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

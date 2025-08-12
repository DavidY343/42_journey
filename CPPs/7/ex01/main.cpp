/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:17:26 by david             #+#    #+#             */
/*   Updated: 2025/08/12 20:19:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void incrementElement(T &elem)
{
	elem += 1;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hola", "Mundo", "C++", "Templates"};
	float floatArray[] = {1.1f, 2.2f, 3.3f};

	std::cout << "=== Array de enteros ===" << std::endl;
	iter(intArray, 5, printElement<int>);

	std::cout << "\nIncrementando..." << std::endl;
	iter(intArray, 5, incrementElement<int>);
	iter(intArray, 5, printElement<int>);

	std::cout << "\n=== Array de strings ===" << std::endl;
	iter(strArray, 4, printElement<std::string>);

	std::cout << "\n=== Array de floats ===" << std::endl;
	iter(floatArray, 3, printElement<float>);

	return 0;
}

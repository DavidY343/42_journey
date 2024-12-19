/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:14:57 by david             #+#    #+#             */
/*   Updated: 2024/12/19 21:14:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating Animal Array ===" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++)
    {
        animals[i] = new Cat();
    }

    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "I want to chase balls!");
    
    Dog* copiedDog = new Dog(*originalDog);
    originalDog->setIdea(0, "I want to sleep!");

    std::cout << "\nOriginal dog's idea: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copied dog's idea: " << copiedDog->getIdea(0) << std::endl;

    delete originalDog;
    delete copiedDog;

    std::cout << "\n=== Cleaning Up Animal Array ===" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        delete animals[i];
    }

    return 0;
}
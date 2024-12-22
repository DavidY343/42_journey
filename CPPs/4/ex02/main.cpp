/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:13:27 by david             #+#    #+#             */
/*   Updated: 2024/12/22 14:09:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
    // Crear una intancia de Animal no es posible, ya que es una clase abstracta:
    //Animal *animal1 = new Animal();
    //Animal animal2 = Animal();

    Dog *dog = new Dog();
    Cat *cat = new Cat();

    delete dog;
    delete cat;

    Animal *array_animals[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
        array_animals[i] = new Dog();
        else
        array_animals[i] = new Cat();
    }

    std::cout << "\n=== Testing makeSound ===" << std::endl;
    
    for (int i = 0; i < 10; i++) array_animals[i]->makeSound();

    for (int i = 0; i < 10; i++) delete array_animals[i];

    std::cout << "\n=== Testing Ideas ===" << std::endl;
    
    Cat *cat2 = new Cat();
    cat2->setIdea(0, "Hmm... fish!");
    cat2->setIdea(1, "I wanna play...");

    std::cout << "cat ideas: " << std::endl;
    std::cout << cat2->getIdea(0) << std::endl;
    std::cout << cat2->getIdea(1) << std::endl;

    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "I want to chase balls!");

    Dog* copiedDog = new Dog(*originalDog);
    originalDog->setIdea(0, "I want to sleep!");

    std::cout << "\nOriginal dog's idea: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copied dog's idea: " << copiedDog->getIdea(0) << std::endl;

    delete originalDog;
    delete copiedDog;
    delete cat2;

    return 0;
}
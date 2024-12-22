/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:14:05 by david             #+#    #+#             */
/*   Updated: 2024/12/20 15:08:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing Animal Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();


    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Testing Wrong Animal (No Polymorphism) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    const WrongCat* wrongCat2 = new WrongCat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();
    wrongCat2->makeSound();

    delete wrongMeta;
    delete wrongCat;
    delete wrongCat2;
    
    return 0;
}
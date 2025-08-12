/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:18:52 by david             #+#    #+#             */
/*   Updated: 2025/08/12 13:18:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data d;
    d.id = 42;
    d.name = "Hello Serialization";

    std::cout << "Original Data pointer: " << &d << std::endl;

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << ptr << std::endl;

    if (ptr == &d)
        std::cout << "Pointers match ✅" << std::endl;
    else
        std::cout << "Pointers do NOT match ❌" << std::endl;

    std::cout << "Data content -> id: " << ptr->id
              << ", name: " << ptr->name << std::endl;

    return 0;
}

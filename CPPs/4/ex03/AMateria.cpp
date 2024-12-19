/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:47:18 by david             #+#    #+#             */
/*   Updated: 2024/12/19 22:18:05 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        // type is const
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return type;
} 

void AMateria::use(ICharacter& target)
{
    (void)target;
}
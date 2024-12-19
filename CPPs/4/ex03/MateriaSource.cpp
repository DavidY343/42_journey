/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:48:12 by david             #+#    #+#             */
/*   Updated: 2024/12/20 00:10:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        templates[i] = other.templates[i] ? other.templates[i]->clone() : NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            {
            delete templates[i];
            templates[i] = other.templates[i] ? other.templates[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    
    for (int i = 0; i < 4; i++)
    {
        if (!templates[i])
        {
            templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] && templates[i]->getType() == type)
        {
            return templates[i]->clone();
        }
    }
    return NULL;
}
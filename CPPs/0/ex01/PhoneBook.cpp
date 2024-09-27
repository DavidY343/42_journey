/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:40:12 by david             #+#    #+#             */
/*   Updated: 2024/09/26 22:12:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(Contact contact)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (this->_contacts[i].getFirstName().empty())
		{
			this->_contacts[i] = contact;
			break ;
		}
		i++;
	}
}

Contact	PhoneBook::getContact(int index)
{
	return (this->_contacts[index]);
}

void PhoneBook::displayContacts()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (!this->_contacts[i].getFirstName().empty())
        {
            std::cout << std::setw(10) << i << "|"
                      << std::setw(10) << truncateString(this->_contacts[i].getFirstName()) << "|"
                      << std::setw(10) << truncateString(this->_contacts[i].getLastName()) << "|"
                      << std::setw(10) << truncateString(this->_contacts[i].getNickname()) << std::endl;
        }
    }
}

std::string truncateString(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayContact(int index)
{
    if (index < 0 || index >= 8 || this->_contacts[index].getFirstName().empty())
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}


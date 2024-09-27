/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:25:59 by david             #+#    #+#             */
/*   Updated: 2024/09/26 22:18:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

static void addContact(PhoneBook &phoneBook)
{
	Contact	contact;
	std::string	input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contact.setNickname(input);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);
	phoneBook.addContact(contact);
}

int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;
	int			index;

	input = "";
	while (1)
	{
		std::cout << "Enter INPUT: ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			addContact(phoneBook);
		}
        else if (input == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "Enter index to display: ";
            std::cin >> index;
            phoneBook.displayContact(index);
        }
		else if (input == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Invalid command: " << input << std::endl;
		}
	}
	return (0);
}
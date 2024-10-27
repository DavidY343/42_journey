/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:25:59 by david             #+#    #+#             */
/*   Updated: 2024/10/27 17:33:28 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

static std::string recieveString(std::string msg)
{
	std::string input;

	while (1)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Unexpected EOF" << std::endl;
			break ;
		}
		if (input == "")
		{
			continue ;
		}
		else
		{
			return (input);
		}
	}
	return ("");
}

static void addContact(PhoneBook &phoneBook)
{
	Contact	contact;
	std::string	input;

	input = recieveString("Enter first name: ");
	if (input == "")
		return ;
	contact.setFirstName(input);
	input = recieveString("Enter last name: ");
	if (input == "")
		return ;
	contact.setLastName(input);
	input = recieveString("Enter nickname: ");
	if (input == "")
		return ;
	contact.setNickname(input);
	input = recieveString("Enter phone number: ");
	if (input == "")
		return ;
	contact.setPhoneNumber(input);
	input = recieveString("Enter darkest secret: ");
	if (input == "")
		return ;
	contact.setDarkestSecret(input);
	phoneBook.addContact(contact);
}

static int getInput(int& index)
{
	std::cout << "Enter index to display: ";
	std::string input;
	std::cin.clear();
	std::getline(std::cin, input);

	if (input.empty())
	{
		std::cout << "Not the right input. Please enter a valid number." << std::endl;
		return (0);
	}
	else
	{
		std::istringstream iss(input);
		if (iss >> index)
		{
			return (1);
		}
		else
		{
			std::cout << "Not the right input. Please enter a valid number." << std::endl;
			return (0);
		}
	}
}

static void searchContact(PhoneBook &phoneBook)
{
	int	index;

	phoneBook.displayContacts();
	//std::cout << "Enter index to display: ";
	/*if (!(std::cin >> index))
	{
		std::cin.clear();
		std::cout << "Not the right input" << std::endl;
		return ;
	}*/
 	if (getInput(index) == 0)
		return ;
	phoneBook.displayContact(index);
}
int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	input = "";
	while (1)
	{
		std::cout << "Enter INPUT: ";
		std::cin.clear();
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Unexpected EOF" << std::endl;
			break ;
		}
		else if (input == "ADD")
		{
			addContact(phoneBook);
		}
        else if (input == "SEARCH")
        {
			searchContact(phoneBook);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:38:51 by david             #+#    #+#             */
/*   Updated: 2024/09/26 20:40:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

std::string	Contact::getFirstName()
{
	return (this->_firstName);
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string	Contact::getLastName()
{
	return (this->_lastName);
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string	Contact::getNickname()
{
	return (this->_nickname);
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getPhoneNumber()
{
	return (this->_phoneNumber);
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string	Contact::getDarkestSecret()
{
	return (this->_darkestSecret);
}
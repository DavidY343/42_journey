/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:40:50 by david             #+#    #+#             */
/*   Updated: 2024/10/27 15:14:01 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
#include <iostream>

std::string truncateString(const std::string &str);

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void		addContact(Contact contact);
		Contact		getContact(int index);
		void		displayContacts();
		void		displayContact(int index);
	private:
		Contact	_contacts[8];
};

#endif
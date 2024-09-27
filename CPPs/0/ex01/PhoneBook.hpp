/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:40:50 by david             #+#    #+#             */
/*   Updated: 2024/09/26 22:13:02 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:34:41 by david             #+#    #+#             */
/*   Updated: 2024/09/26 21:37:02 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		void		setFirstName(std::string firstName);
		std::string	getFirstName();
		void		setLastName(std::string lastName);
		std::string	getLastName();
		void		setNickname(std::string nickname);
		std::string	getNickname();
		void		setPhoneNumber(std::string phoneNumber);
		std::string	getPhoneNumber();
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getDarkestSecret();
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
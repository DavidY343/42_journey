/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:30:27 by david             #+#    #+#             */
/*   Updated: 2024/10/29 19:35:38 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		
		struct ComplaintLevel
		{
			std::string level;
			void (Harl::*func)(void);
		};
		
		static ComplaintLevel complaintLevels[4];

	public:
		void complain(std::string level);
};

#endif
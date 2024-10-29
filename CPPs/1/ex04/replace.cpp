/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:13:53 by david             #+#    #+#             */
/*   Updated: 2024/10/29 19:21:27 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string ft_replace(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t lastPos = 0;
	size_t findPos;

	while ((findPos = line.find(s1, lastPos)) != std::string::npos)
	{
		result.append(line, lastPos, findPos - lastPos);
		result += s2;
		lastPos = findPos + s1.length();
	}
	result.append(line, lastPos, line.length() - lastPos);
	return (result);
}
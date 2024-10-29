/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:13:28 by david             #+#    #+#             */
/*   Updated: 2024/10/29 19:37:50 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "replace.hpp"

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: string to replace cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: cannot open input file: " << filename << std::endl;
		return (1);
	}

	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: cannot create output file: " << outFilename << std::endl;
		inFile.close();
		return (1);
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		outFile << ft_replace(line, s1, s2);
		if (!inFile.eof())
		{
			outFile << std::endl;
		}
	}
	inFile.close();
	outFile.close();
	return (0);
}
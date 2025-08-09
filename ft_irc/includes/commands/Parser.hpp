/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:09:22 by jonjimen          #+#    #+#             */
/*   Updated: 2025/06/19 13:13:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>
#include <sstream>
#include <iostream>

class Server;
class Client;


#include "Command.hpp"

class Command;

class Parser {
private:
    Server* _srv;
    std::map<std::string, Command*> _commands;

public:
    Parser(Server* srv);
    ~Parser();

    void main(Client* client, const std::string& message);
    void parseLine(const std::string& line, std::string& cmdName, std::vector<std::string>& args);
    std::string trim(const std::string& str);
};

#endif // PARSER_HPP

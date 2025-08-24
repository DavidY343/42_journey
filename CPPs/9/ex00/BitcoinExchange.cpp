/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:17:51 by david             #+#    #+#             */
/*   Updated: 2025/08/24 23:19:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::string date, priceStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, priceStr))
            continue;
        double price = std::atof(priceStr.c_str());
        _db[date] = price;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
        return false;
    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const {
    std::stringstream ss(valueStr);
    ss >> value;
    if (ss.fail() || !ss.eof())
        return false;
    if (value < 0)
        return false;
    if (value > 1000)
        return false;
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end()) {
        --it;
        return it->first;
    }
    if (it->first == date)
        return date;
    if (it == _db.begin())
        return "";
    --it;
    return it->first;
}

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!date.empty() && date[date.size()-1] == ' ')
            date.erase(date.size()-1);
        if (!valueStr.empty() && valueStr[0] == ' ')
            valueStr.erase(0, 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        if (!isValidValue(valueStr, value)) {
            if (valueStr.find('-') != std::string::npos)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (std::atof(valueStr.c_str()) > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string closestDate = findClosestDate(date);
        if (closestDate.empty()) {
            std::cerr << "Error: no valid date found in database." << std::endl;
            continue;
        }

        double rate = _db.find(closestDate)->second;
        double result = value * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

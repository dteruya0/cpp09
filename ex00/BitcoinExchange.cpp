/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:36:44 by dteruya           #+#    #+#             */
/*   Updated: 2026/08/15 10:43:35 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->_database = other._database;
    return *this;
}

void BitcoinExchange::loadDataBase(const std::string &filename)
{
    // abrir o data.csv
    // ignorar a primeira linha: date,exchange_rate
    // ler linha por linha
    // separar a data da cotação pela vírgula
    // guardar no map

	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Could not open file" << std::endl;
		return;
	}
	std::string line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos;
		pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		std::stringstream valStr(rateStr);
		float rate;
		valStr >> rate;
		_database[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string& filename)
{
    // abrir o arquivo
    // ignorar a primeira linha
    // ler linha por linha
    // validar cada linha
    // calcular o resultado se estiver certo
    // mostrar erro se estiver errado

	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Could not open file" << std::endl;
		return;
	}
	std::string line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos;
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		while (!date.empty() && date[date.length() - 1] == ' ')
    		date.erase(date.length() - 1);
		std::string valueStr = line.substr(pos + 1);
		std::stringstream valStr(valueStr);
		double value;
		char extra;

		if (!(valStr >> value) || (valStr >> extra))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string numbers = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);

		if (numbers.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		int year = atoi(date.substr(0, 4).c_str());
		int month = atoi(date.substr(5, 2).c_str());
		int day = atoi(date.substr(8, 2).c_str());
		if (month < 1 || month > 12)
		{
			std::cerr << "Error: month invalid value." << std::endl;
			continue;
		}

		int daysInMonth;

		if (month == 2)
		{
			if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
				daysInMonth = 29;
			else
				daysInMonth = 28;
		}
		else if (month == 4 || month == 6 ||
				month == 9 || month == 11)
		{
			daysInMonth = 30;
		}
		else
		{
			daysInMonth = 31;
		}

		if (day < 1 || day > daysInMonth)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it;
		it = _database.lower_bound(date);

		if (it == _database.begin() && it->first != date)
		{
			std::cerr << "Error: no exchange rate available for this date." << std::endl;
			continue;
		}
		if (it == _database.end())
			--it;
		else if (it->first != date)
			--it;
		double result = value * it->second;

		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

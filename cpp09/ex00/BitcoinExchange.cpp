/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:14:10 by aperin            #+#    #+#             */
/*   Updated: 2023/04/13 09:20:02 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file;
	std::string		str;
	std::string		date;
	float			value;
	std::size_t		pos;

	file.open("data.csv", std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "data.csv: could not open file\n";
		return ;
	}
	std::getline(file, str);
	while (!file.eof())
	{
		std::getline(file, str);
		if (str.empty())
			continue ;
		pos = str.find(',');
		date = str.substr(0, pos);
		value = std::strtof(str.substr(pos + 1).c_str(), NULL);
		this->_map.insert(std::pair<std::string, float>(date, value));
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::process_input(const std::string &filename)
{
	std::ifstream	file;
	std::string		str;
	std::string		date;
	float			value;
	std::size_t		pos;
	std::size_t		lpos;
	std::size_t		rpos;

	file.open(filename.c_str(), std::ios::in);
	if (!file.is_open())
	{
		std::cerr << filename << ": could not be opened\n";
		return ;
	}
	std::getline(file, str);
	while (!file.eof())
	{
		std::getline(file, str);
		if (str.empty())
			continue ;
		pos = str.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << str << std::endl;
			continue ;
		}
		lpos = str.find_first_not_of(WHITESPACES);
		rpos = str.find_last_not_of(WHITESPACES, pos - 1);
		if (lpos == pos)
		{
			std::cout << "Error: bad input => " << str << std::endl;
			continue ;
		}
		date = str.substr(lpos, rpos - lpos + 1);
		lpos = str.find_first_not_of(WHITESPACES, pos + 1);
		rpos = str.find_last_not_of(WHITESPACES);
		if (rpos == pos)
		{
			std::cout << "Error: bad input => " << str << std::endl;
			continue ;
		}
		value = std::strtof(str.substr(lpos).c_str(), NULL);
		if (!valid_date(date))
			std::cout << "Error: invalid date format.\n";
		else if (!valid_number(str.substr((lpos))))
			std::cout << "Error: invalid number.\n";
		else if (value < 0)
			std::cout << "Error: not a positive number.\n";
		else if (value > 1000)
			std::cout << "Error: too large a number.\n";
		else
			std::cout << date << ", " << value << std::endl;
	}
	file.close();
}

bool BitcoinExchange::valid_date(const std::string &date)
{
	if (date.length() != 10)
		return false;
	for (int i = 0; i < 4; i++)
		if (!isdigit(date[i]))
			return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	if (!isdigit(date[5]) || !isdigit(date[6])
		|| !isdigit(date[8]) || !isdigit(date[9]))
		return false;
	return true;
}

bool BitcoinExchange::valid_number(const std::string &number)
{
	for (unsigned long i = 0; i < number.length(); i++)
		if (!isdigit(number[i]))
			return false;
	return true;
}

void	BitcoinExchange::print_map()
{
	std::map<std::string, float>::iterator	it = this->_map.begin();
	std::map<std::string, float>::iterator	ite = this->_map.end();
	for (; it != ite; it++)
		std::cout << it->first << ", " << it->second << std::endl;
}

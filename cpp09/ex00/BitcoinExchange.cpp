/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:14:10 by aperin            #+#    #+#             */
/*   Updated: 2023/04/18 14:40:13 by aperin           ###   ########.fr       */
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
	std::string		str, date;
	float			value;
	size_t			pos;

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
		date = _parse_date(str, pos);
		if (date.empty())
			continue ;
		value = _parse_number(str, pos);
		if (value < 0)
			continue ;
		_find_rate(date, value);
	}
	file.close();
}

std::string	BitcoinExchange::_parse_date(std::string &str, size_t pos)
{
	size_t	lpos, rpos;
	std::string	date;

	lpos = str.find_first_not_of(WHITESPACES);
	rpos = str.find_last_not_of(WHITESPACES, pos - 1);
	if (lpos == pos)
	{
		std::cout << "Error: bad input => " << str << std::endl;
		return std::string();
	}
	date = str.substr(lpos, rpos - lpos + 1);
	if (!_valid_date(date))
	{
		std::cout << "Error: invalid date format.\n";
		return std::string();
	}
	return date;
}

float	BitcoinExchange::_parse_number(std::string &str, size_t pos)
{
	size_t	lpos, rpos;
	float	value;

	lpos = str.find_first_not_of(WHITESPACES, pos + 1);
	rpos = str.find_last_not_of(WHITESPACES);
	if (rpos == pos)
	{
		std::cout << "Error: bad input => " << str << std::endl;
		return -1;
	}
	value = std::strtof(str.substr(lpos).c_str(), NULL);
	if (errno == ERANGE || !_valid_number(str.substr(lpos, rpos - lpos + 1)))
		std::cout << "Error: invalid number.\n";
	else if (value < 0)
		std::cout << "Error: not a positive number.\n";
	else if (value > 1000)
		std::cout << "Error: too large a number.\n";
	else
		return value;
	return -1;
}

bool BitcoinExchange::_valid_date(const std::string &date)
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

bool BitcoinExchange::_valid_number(const std::string &number)
{
	int	count = 0;
	unsigned long	i = 0;

	if (number[i] == '-')
		i++;
	while (i < number.length())
	{
		if (!isdigit(number[i]) && number[i] != '.')
			return false;
		if (number[i] == '.')
			count++;
		i++;
	}
	if (count > 1)
		return false;
	return true;
}

void	BitcoinExchange::_find_rate(std::string &date, float value)
{
	std::map<std::string, float>::iterator	it = this->_map.upper_bound(date);
	if (it == this->_map.begin())
	{
		std::cout << date << " => no data available.\n";
		return ;
	}
	it--;
	std::cout << date << " => " << value << " = " << value * it->second;
	std::cout << std::endl;
}

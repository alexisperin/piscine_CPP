/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:14:10 by aperin            #+#    #+#             */
/*   Updated: 2023/04/12 16:20:21 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

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

	file.open(filename, std::ios::in);
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
		date = str.substr(lpos, pos);
		rpos = date.find_last_not_of(WHITESPACES);
		date = date.substr(lpos, rpos);
		str = str.substr(pos + 1);
		lpos = str.find_first_not_of(WHITESPACES);
		rpos = str.find_last_not_of(WHITESPACES);
		value = std::strtof(str.substr(lpos, rpos).c_str(), NULL);
		std::cout << date << ", " << value << std::endl;
	}
	file.close();
}

void	BitcoinExchange::print_map()
{
	std::map<std::string, float>::iterator	it = this->_map.begin();
	std::map<std::string, float>::iterator	ite = this->_map.end();
	for (; it != ite; it++)
		std::cout << it->first << ", " << it->second << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:38:57 by aperin            #+#    #+#             */
/*   Updated: 2023/01/05 09:21:39 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_nb_contacts = 0;
	std::cout << "New phonebook created !" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook deleted !" << std::endl;
}

void	PhoneBook::add()
{
	std::cout << "First name: ";
	this->_contacts[this->_index % 8].set_first_name(_read_info());

	std::cout << "Last name: ";
	this->_contacts[this->_index % 8].set_last_name(_read_info());

	std::cout << "Nickname: ";
	this->_contacts[this->_index % 8].set_nickname(_read_info());

	std::cout << "Phone number: ";
	this->_contacts[this->_index % 8].set_number(_read_info());

	std::cout << "Darkest secret: ";
	this->_contacts[this->_index % 8].set_secret(_read_info());

	std::cout << "New contact saved" << std::endl;
	this->_index = (this->_index + 1) % 8;
	if (this->_nb_contacts < 8)
		this->_nb_contacts++;
}

void	PhoneBook::search() const
{
	std::cout << "  Index   |First name| Last name| Nickname " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < this->_nb_contacts; i++)
	{
		std::cout << "         " << i + 1 << '|';
		_print_str(this->_contacts[i].get_first_name());
		std::cout << '|';
		_print_str(this->_contacts[i].get_last_name());
		std::cout << '|';
		_print_str(this->_contacts[i].get_nickname());
		std::cout << std::endl;
	}
	std::cout << "Select a contact: ";
}

std::string	PhoneBook::_read_info() const
{
	std::string	str;

	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "Please enter some information" << std::endl;
		std::getline(std::cin, str);
	}while (str.empty());
	return str;
}

void	PhoneBook::_print_str(std::string str) const
{
	int	len = str.size();

	if (len > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::string(10 - len, ' ') << str;
}

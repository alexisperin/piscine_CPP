/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:38:57 by aperin            #+#    #+#             */
/*   Updated: 2023/01/04 16:40:11 by aperin           ###   ########.fr       */
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
	std::string	str;

	std::cout << "First name: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index % 8].set_first_name(str);

	std::cout << "Last name: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index % 8].set_last_name(str);

	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index % 8].set_nickname(str);

	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index % 8].set_number(str);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	this->_contacts[this->_index % 8].set_secret(str);

	if (this->_index < 7)
		this->_index++;
	else
		this->_index = 0;
	if (this->_nb_contacts < 8)
		this->_nb_contacts++;
}

void	PhoneBook::search() const
{
	std::string	str;

	std::cout << "  Index   |First name| Last name| Nickname " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < this->_index; i++)
	{
		std::cout << "         " << i << '|';
		_print_str(this->_contacts[i].get_first_name());
		std::cout << '|';
		_print_str(this->_contacts[i].get_last_name());
		std::cout << '|';
		_print_str(this->_contacts[i].get_nickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::_print_str(std::string str) const
{
	int	len = str.size();

	if (len > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::string(10 - len, ' ') << str;
}

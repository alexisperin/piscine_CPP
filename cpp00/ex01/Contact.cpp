/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:57:47 by aperin            #+#    #+#             */
/*   Updated: 2023/01/04 11:05:01 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

// Getters
std::string	Contact::get_first_name() const
{
	return this->_first_name;
}

std::string	Contact::get_last_name() const
{
	return this->_last_name;
}

std::string	Contact::get_nickname() const
{
	return this->_nickname;
}

std::string	Contact::get_number() const
{
	return this->_number;
}

std::string	Contact::get_secret() const
{
	return this->_secret;
}

// Setters
void	Contact::set_first_name(std::string str)
{
	this->_first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::set_number(std::string str)
{
	this->_number = str;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}

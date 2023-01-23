/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:00:26 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 09:09:19 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"
#include <iostream>
#include <stdlib.h>
#include <sstream>

Literal::Literal(): _s("")
{
}

Literal::Literal(const std::string input): _s(input)
{
	this->_toType();
}

Literal::Literal(const Literal &copy): _s(copy._s)
{
}

Literal::~Literal()
{
}

Literal	&Literal::operator=(const Literal &copy)
{
	(void) copy;
	return *this;
}

void	Literal::_toType()
{
	std::string	input = this->_s;

	//Check non displayable characters
	for (int i = 0; input[i]; i++)
		if (!isprint(input[i]))
		{
			std::cout << "Use of non displayable characters is not allowed\n";
			return;
		}

	// Check char
	if (input.size() == 1 && !isdigit(input[0]))
		return this->_toChar();

	//Check int
	int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] == 0)
		return this->_toInt();
	
	//Check float
	int dot = 0;
	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (isdigit(input[i]) || input[i] == '.')
	{
		if (input[i] == '.')
			dot++;
		i++;
	}
	if (input[i] == 'f' && dot == 1 && input[i + 1] == 0)
		return this->_toFloat();
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return this->_toFloat();

	//Check double
	dot = 0;
	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++; 
	while (isdigit(input[i]) || input[i] == '.')
	{
		if (input[i] == '.')
			dot++;
		i++;
	}
	if (dot == 1 && input[i] == 0)
		return this->_toDouble();
	if (input == "-inf" || input == "+inf" || input == "nan")
		return this->_toDouble();
	this->_type = -1;
}

void	Literal::_toChar()
{
	this->_flags = {1, 1, 1, 1};
	this->_c = this->_s[0];
	this->_i = static_cast<int>(this->_c);
	this->_f = static_cast<float>(this->_c);
	this->_d = static_cast<double>(this->_c);
}

void	Literal::_toInt()
{
	this->_i = atoi(this->_s.c_str());
	this->_c = static_cast<int>(this->_i);
	this->_f = static_cast<float>(this->_i);
	this->_d = static_cast<double>(this->_i);
}

void	Literal::_toFloat()
{
	// this->_c = this->_s[0];
	// this->_i = static_cast<int>(this->_c);
	// this->_f = static_cast<float>(this->_c);
	// this->_d = static_cast<double>(this->_c);
}

void	Literal::_toDouble()
{
	// this->_c = this->_s[0];
	// this->_i = static_cast<int>(this->_c);
	// this->_f = static_cast<float>(this->_c);
	// this->_d = static_cast<double>(this->_c);
}

void	Literal::displayLiteral() const
{
	if (this->_flags[0] == -1)
		std::cout << "char: non displayable\n";
	else if (this->_flags[0] == 0)
		std::cout << "char: impossible\n";
	else
		std::cout << "char: " << this->_c << std::endl;
	
	if (this->_flags[1] == 0)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << this->_i << std::endl;

	if (this->_flags[2] == 0)
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << this->_i << std::endl;
		
	if (this->_flags[3] == 0)
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << this->_i << std::endl;
}

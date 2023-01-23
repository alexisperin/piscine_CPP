/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:00:26 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 11:55:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"
#include <iostream>
#include <sstream>
#include <cfloat>

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
	if (input[i] == 'f' && dot <= 1 && input[i + 1] == 0)
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

	std::cout << "Impossible convertion\nSupported types are <char>, <int>, "
		<< "<float> and <double>\n";
}

void	Literal::_toChar()
{
	char	c = this->_s[0];

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void	Literal::_toInt()
{
	std::istringstream	iss(this->_s);
	std::istringstream	iss2(this->_s);
	int		n;
	long	l;

	iss >> n;
	iss2 >> l;
	if (n != l)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: overflow\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}
	if (!isprint(static_cast<char>(n)))
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(n) << "'\n";
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f\n";
	std::cout << "double: " << static_cast<double>(n) << ".0\n";
}

void	Literal::_toFloat()
{
	double	n;

	if (this->_s == "-inff" || this->_s == "+inff" || this->_s == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << this->_s << std::endl;
		std::cout << "double: " << this->_s.substr(0, this->_s.size() - 1)
			<< std::endl;
		return ;
	}
	n = strtod(this->_s.c_str(), NULL);
	if (n == HUGE_VAL || n == -HUGE_VAL || errno == ERANGE
		|| (float) n < n || (float) n > n)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: overflow\n";
		std::cout << "double: impossible\n";
		return;
	}
	if (!isprint(static_cast<char>(n)))
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(n) << "'\n";
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << n;
	if ((int) n == n)
		std::cout << ".0f\n";
	else
		std::cout << "f\n";
	std::cout << "double: " << static_cast<double>(n);
	if ((int) n == n)
		std::cout << ".0";
	std::cout << std::endl;
}

void	Literal::_toDouble()
{
	double	n;

	if (this->_s == "-inf" || this->_s == "+inf" || this->_s == "nan")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << this->_s << "f\n";
		std::cout << "double: " << this->_s << std::endl;
		return ;
	}
	n = strtod(this->_s.c_str(), NULL);
	if (n == HUGE_VAL || n == -HUGE_VAL || errno == ERANGE)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: overflow\n";
		return;
	}
	if (!isprint(static_cast<char>(n)))
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(n) << "'\n";
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << static_cast<float>(n);
	if ((int) n == n)
		std::cout << ".0f\n";
	else
		std::cout << "f\n";
	std::cout << "double: " << n;
	if ((int) n == n)
		std::cout << ".0";
	std::cout << std::endl;
}

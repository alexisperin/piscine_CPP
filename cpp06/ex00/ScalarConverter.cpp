/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:22:06 by aperin            #+#    #+#             */
/*   Updated: 2023/04/04 13:15:39 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cfloat>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return *this;
}

void	ScalarConverter::convert(std::string str)
{
	//Check non displayable characters
	for (int i = 0; str[i]; i++)
		if (!isprint(str[i]))
		{
			std::cout << "Use of non displayable characters is not allowed\n";
			return;
		}

	// Check char
	if (str.size() == 1 && !isdigit(str[0]))
		return ScalarConverter::_toChar(str);

	//Check int
	int i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] == 0)
		return ScalarConverter::_toInt(str);
	
	//Check float
	int dot = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (isdigit(str[i]) || str[i] == '.')
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (str[i] == 'f' && dot <= 1 && str[i + 1] == 0)
		return ScalarConverter::_toFloat(str);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return ScalarConverter::_toFloat(str);

	//Check double
	dot = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++; 
	while (isdigit(str[i]) || str[i] == '.')
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (dot == 1 && str[i] == 0)
		return ScalarConverter::_toDouble(str);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return ScalarConverter::_toDouble(str);

	std::cout << "Impossible convertion\nSupported types are <char>, <int>, "
		<< "<float> and <double>\n";
}

void	ScalarConverter::_toChar(std::string str)
{
	char	c = str[0];

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void	ScalarConverter::_toInt(std::string str)
{
	std::istringstream	iss(str);
	std::istringstream	iss2(str);
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

void	ScalarConverter::_toFloat(std::string str)
{
	float	n;

	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.size() - 1)
			<< std::endl;
		return ;
	}
	n = strtof(str.c_str(), NULL);
	if (n == HUGE_VALF || n == -HUGE_VALF || errno == ERANGE)
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

void	ScalarConverter::_toDouble(std::string str)
{
	double	n;

	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << str << "f\n";
		std::cout << "double: " << str << std::endl;
		return ;
	}
	n = strtod(str.c_str(), NULL);
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

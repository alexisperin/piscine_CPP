/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:44:02 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 14:11:01 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <cstdlib>

Data::Data()
{
	srand(time(NULL));
	this->_a = rand() % 19;
	this->_b = rand() % 42;
}

Data::Data(const Data &copy)
{
	*this = copy;
}

Data::~Data()
{
}

Data	&Data::operator=(const Data &copy)
{
	this->_a = copy._a;
	this->_b = copy._b;

	return *this;
}

int		Data::getA() const
{
	return this->_a;
}

int		Data::getB() const
{
	return this->_b;
}

std::ostream	&operator<<(std::ostream &out, const Data &data)
{
	out << "a: " << data.getA() << ", b: " << data.getB();

	return out;
}

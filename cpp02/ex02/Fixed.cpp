/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:35:43 by aperin            #+#    #+#             */
/*   Updated: 2023/01/12 10:08:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_point = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed(const int &val)
{
	std::cout << "Int constructor called\n";
	this->_point = val << this->_frac;
}

Fixed::Fixed(const float &val)
{
	std::cout << "Float constructor called\n";
	this->_point = roundf(val * (1 << this->_frac));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	this->_point = copy.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const
{
	return this->_point;
}

void	Fixed::setRawBits(const int raw)
{
	this->_point = raw;
}

float	Fixed::toFloat() const
{
	return (float) this->_point / (1 << this->_frac);
}

int		Fixed::toInt() const
{
	return this->_point >> this->_frac;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

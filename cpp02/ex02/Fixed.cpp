/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:35:43 by aperin            #+#    #+#             */
/*   Updated: 2023/01/12 11:27:07 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->_point = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int &val)
{
	this->_point = val << this->_frac;
}

Fixed::Fixed(const float &val)
{
	this->_point = roundf(val * (1 << this->_frac));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	this->_point = copy.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return this->toFloat() > fixed.toFloat();
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return this->toFloat() < fixed.toFloat();
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return this->toFloat() >= fixed.toFloat();
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return this->toFloat() <= fixed.toFloat();
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return this->toFloat() == fixed.toFloat();
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return this->toFloat() != fixed.toFloat();
}

Fixed	&Fixed::operator+(const Fixed &fixed)
{
	Fixed	ret(this->toFloat() + fixed.toFloat());
	return ret;
}

Fixed	&Fixed::operator-(const Fixed &fixed)
{
	Fixed	ret(this->toFloat() - fixed.toFloat());
	return ret;
}

Fixed	&Fixed::operator*(const Fixed &fixed)
{
	Fixed	ret(this->toFloat() * fixed.toFloat());
	return ret;
}

Fixed	&Fixed::operator/(const Fixed &fixed)
{
	Fixed	ret(this->toFloat() / fixed.toFloat());
	return ret;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:35:43 by aperin            #+#    #+#             */
/*   Updated: 2023/03/21 16:58:56 by aperin           ###   ########.fr       */
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
	return this->getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return this->getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return this->getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return this->getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return this->getRawBits() != fixed.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + fixed.getRawBits());
	return res;
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - fixed.getRawBits());
	return res;
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	Fixed	res;

	res.setRawBits(((long) this->_point * (long) fixed._point) >> this->_frac);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	Fixed	res;

	res.setRawBits(((long) this->_point << this->_frac) / (long) fixed._point);
	return (res);
}

Fixed	&Fixed::operator++()
{
	this->_point++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	prev(*this);
	this->_point++;
	return prev;
}

Fixed	&Fixed::operator--()
{
	this->_point--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	prev(*this);
	this->_point--;
	return prev;
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:05 by aperin            #+#    #+#             */
/*   Updated: 2023/01/12 12:58:31 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_point;
		static const int	_frac = 8;

		

	public:
		//Constructor/destructor
		Fixed();
		Fixed(const Fixed &val);
		Fixed(const int &val);
		Fixed(const float &val);
		~Fixed();

		//Assignment operators
		Fixed	&operator=(const Fixed &copy);

		//Comparison operators
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		//Arithmetic operators
		Fixed	&operator+(const Fixed &fixed);
		Fixed	&operator-(const Fixed &fixed);
		Fixed	&operator*(const Fixed &fixed);
		Fixed	&operator/(const Fixed &fixed);

		//Increment/decrement operators
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++();
		Fixed	operator++();

		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif

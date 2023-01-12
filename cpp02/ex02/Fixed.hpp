/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:05 by aperin            #+#    #+#             */
/*   Updated: 2023/01/12 10:10:52 by aperin           ###   ########.fr       */
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
		Fixed();
		Fixed(const Fixed &val);
		Fixed(const int &val);
		Fixed(const float &val);
		~Fixed();

		Fixed	&operator=(const Fixed &copy);

		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif

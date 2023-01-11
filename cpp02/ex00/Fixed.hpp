/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:29:05 by aperin            #+#    #+#             */
/*   Updated: 2023/01/11 16:45:27 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_point;
		static const int	_frac = 8;

	public:
		Fixed();
		Fixed(const Fixed &point);
		~Fixed();
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits() const;
		void	setRawBits(const int raw);
};

#endif

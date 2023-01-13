/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:19:37 by aperin            #+#    #+#             */
/*   Updated: 2023/01/13 08:47:15 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONT_HPP
# define PONT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		//Constructor/destructor
		Point();
		Point(const Point &copy);
		Point(const float x, const float y);
		~Point();

		//Assignment operators
		Point	&operator=(Point &copy);

		//Other functions
		Fixed	getX() const;
		Fixed	getY() const;
};

#endif

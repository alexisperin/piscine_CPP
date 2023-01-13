/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:25:57 by aperin            #+#    #+#             */
/*   Updated: 2023/01/13 08:47:26 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY())
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Point::~Point()
{
}

Point	&Point::operator=(Point &copy)
{
	return copy;
}

Fixed	Point::getX() const
{
	return this->_x;
}

Fixed	Point::getY() const
{
	return this->_y;
}

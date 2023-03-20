/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:07:18 by aperin            #+#    #+#             */
/*   Updated: 2023/03/20 12:02:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	area(const Point p1, const Point p2, const Point p3)
{
	Fixed	area;

	area =  (p1.getX() * (p2.getY() - p3.getY())
			+ p2.getX() * (p3.getY() - p1.getY())
			+ p3.getX() * (p1.getY() - p2.getY()))
			/ 2;
	if (area < 0)
		return Fixed(0) - area;
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A(area(a, b, c));
	Fixed	A1(area(a, b, point));
	Fixed	A2(area(a, c, point));
	Fixed	A3(area(b, c, point));

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return false;
	return A == A1 + A2 + A3;
}
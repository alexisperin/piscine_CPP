/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:50:56 by aperin            #+#    #+#             */
/*   Updated: 2023/03/20 12:09:52 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

static void	test_case( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "Point " << point.getX() << ", " << point.getY()
		<< " in triangle : " << bsp(a, b, c, point) << std::endl;
}

int main()
{
	Point const	a(0.0, 0.0);
	Point const	b(3.0, 0.0);
	Point const	c(1.5, 3.0);

	std::cout << "a : " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "b : " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "c : " << c.getX() << ", " << c.getY() << std::endl;
	std::cout << std::endl;
	
	test_case(a, b, c, Point(0.5, 0.5));
	test_case(a, b, c, Point(1.5, 1.5));
	test_case(a, b, c, Point(0.5, -0.5));
	test_case(a, b, c, Point(1.5, 0.0));
	test_case(a, b, c, Point(1.5, 2.9));
	test_case(a, b, c, Point(1.5, 2.5));
	test_case(a, b, c, Point(1.5, 3.1));
	test_case(a, b, c, a);

	return 0;
}

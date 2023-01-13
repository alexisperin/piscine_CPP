/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:50:56 by aperin            #+#    #+#             */
/*   Updated: 2023/01/13 09:22:37 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point	a(0, 0);
	Point	b(10, 30);
	Point	c(20, 0);

	std::cout << "Inside: " << bsp(a, b, c, Point(10, 15)) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, Point(40, 40)) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, Point(0, 0.01f)) << std::endl;
	std::cout << "One of the vertices: " << bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << "On the edge: " << bsp(a, b, c, Point(5, 15)) << std::endl;

	return 0;
} 

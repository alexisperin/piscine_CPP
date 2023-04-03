/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:01 by aperin            #+#    #+#             */
/*   Updated: 2023/04/03 11:48:30 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat	a("Michel", 150);
		std::cout << a << std::endl;
		a.upGrade();
		std::cout << a << std::endl;
		a.downGrade();
		std::cout << a << std::endl;
		a.downGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b("Claude", 160);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	c("Danny", -1);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}



	return 0;
}

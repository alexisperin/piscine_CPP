/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:01 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 09:08:11 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "--- TEST 1 ---\n";
		Bureaucrat	a("Michel", 150);
		std::cout << a << std::endl;
		Bureaucrat	b("Claude", 10);
		std::cout << b << std::endl;
		Form		f1("Form 1", 100, 50);
		std::cout << f1 << std::endl;
		Form		f2("Form 2", 0, 50);
		std::cout << f2 << std::endl;

		a.signForm(f1);
		b.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- TEST 2 ---\n";
		Bureaucrat	a("Michel", 150);
		std::cout << a << std::endl;
		Bureaucrat	b("Claude", 10);
		std::cout << b << std::endl;
		Form		f1("Form 1", 100, 50);
		std::cout << f1 << std::endl;

		a.signForm(f1);
		std::cout << f1 << std::endl;
		b.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

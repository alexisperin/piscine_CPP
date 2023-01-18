/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:01 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 13:39:05 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
		ShrubberyCreationForm	f1("DBZ");
		std::cout << f1 << std::endl;

		a.signForm(f1);
		b.signForm(f1);
		std::cout << f1 << std::endl;
		a.executeForm(f1);
		b.executeForm(f1);
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
		RobotomyRequestForm	f1("DBZ");
		std::cout << f1 << std::endl;

		a.signForm(f1);
		b.signForm(f1);
		std::cout << f1 << std::endl;
		a.executeForm(f1);
		b.executeForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- TEST 3 ---\n";
		Bureaucrat	a("Michel", 15);
		std::cout << a << std::endl;
		Bureaucrat	b("Claude", 1);
		std::cout << b << std::endl;
		PresidentialPardonForm	f1("DBZ");
		std::cout << f1 << std::endl;

		a.signForm(f1);
		std::cout << f1 << std::endl;
		a.executeForm(f1);
		b.executeForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- TEST 4 ---\n";
		Bureaucrat	a("Michel", 1);
		std::cout << a << std::endl;
		ShrubberyCreationForm	f1("DBZ");
		std::cout << f1 << std::endl;
		RobotomyRequestForm	f2("DBS");
		std::cout << f2 << std::endl;
		PresidentialPardonForm	f3("DBGT");
		std::cout << f3 << std::endl;

		a.executeForm(f1);
		a.executeForm(f2);
		a.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

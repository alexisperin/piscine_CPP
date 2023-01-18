/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:56:01 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 16:40:02 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "--- TEST 1 ---\n";
		Bureaucrat	mich("Michel", 150);
		std::cout << mich << std::endl;

		Intern	i;
		AForm	*f1 = i.makeForm("bad form", "some target");

		delete f1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\n--- TEST 2 ---\n";
		Bureaucrat	mich("Michel", 137);
		std::cout << mich << std::endl;

		Intern	i;
		AForm	*f1 = i.makeForm("shrubbery creation", "DBZ");

		std::cout << *f1 << std::endl;
		mich.signForm(*f1);
		std::cout << *f1 << std::endl;
		mich.executeForm(*f1);

		delete f1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

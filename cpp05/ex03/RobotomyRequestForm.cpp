/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:50:10 by aperin            #+#    #+#             */
/*   Updated: 2023/04/03 12:09:52 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", "", 72, 45)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", target, 72, 45)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm("RobotomyRequestForm", copy.getTarget(), 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	(void) copy;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw RobotomyRequestForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExe())
		throw RobotomyRequestForm::GradeTooLowException();

	std::cout << "!!! DRILLING NOISE !!!\n";
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized\n";
	else
		std::cout << this->getTarget() << " couldn't be robotomized\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:20:19 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 13:28:03 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", "", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	AForm("PresidentialPardonForm", copy.getTarget(), 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	(void) copy;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw PresidentialPardonForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExe())
		throw PresidentialPardonForm::GradeTooLowException();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}

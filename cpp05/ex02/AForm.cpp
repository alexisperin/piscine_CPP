/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:31:24 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 09:03:00 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name(""), _target(""), _signed(false), _grade_sign(19),
	_grade_exe(19)
{
}

AForm::AForm(const std::string &name, const std::string &target,
	int grade_sign, int grade_exe): _name(name), _target(target),
		_signed(false), _grade_sign(grade_sign), _grade_exe(grade_exe)
{
	if (grade_sign <= 0 || grade_exe <= 0)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_exe > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy): _name(copy._name), _target(copy._target),
	_signed(copy._signed), _grade_sign(copy._grade_sign),
	_grade_exe(copy._grade_exe)
{
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(const AForm &copy)
{
	this->_name = copy._name;
	this->_target = copy._target;
	this->_signed = copy._signed;

	return *this;
}

std::string	AForm::getName() const
{
	return this->_name;
}

std::string	AForm::getTarget() const
{
	return this->_target;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

int	AForm::getGradeSign() const
{
	return this->_grade_sign;
}

int	AForm::getGradeExe() const
{
	return this->_grade_exe;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("[Grade Too High Exception]");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("[Grade Too Low Exception]");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("[Form Not Signed Exception]");
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << ", signed: " << f.getSigned() << ", grade to sign: "
		<< f.getGradeSign() << "; grade to execute: " << f.getGradeExe();

		return out;
}

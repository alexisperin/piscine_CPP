/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:31:24 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 09:03:00 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(""), _signed(false), _grade_sign(19), _grade_exe(19)
{
}

Form::Form(const std::string &name, int grade_sign, int grade_exe):
	_name(name), _signed(false), _grade_sign(grade_sign), _grade_exe(grade_exe)
{
	if (grade_sign <= 0 || grade_exe <= 0)
		throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_exe > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed),
	_grade_sign(copy._grade_sign), _grade_exe(copy._grade_exe)
{
	
}

Form::~Form()
{
}

Form	&Form::operator=(const Form &copy)
{
	this->_name = copy._name;
	this->_signed = copy._signed;

	return *this;
}

const std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

int	Form::getGradeSign() const
{
	return this->_grade_sign;
}

int	Form::getGradeExe() const
{
	return this->_grade_exe;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("[Grade Too High Exception]");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("[Grade Too Low Exception]");
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << ", signed: " << f.getSigned() << ", grade to sign: "
		<< f.getGradeSign() << "; grade to execute: " << f.getGradeExe();

		return out;
}

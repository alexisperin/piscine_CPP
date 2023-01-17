/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:46 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 18:21:10 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("")
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;		
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name),
	_grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy._grade;

	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::upGrade(int amount)
{
	if (this->_grade - amount <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= amount;
}

void	Bureaucrat::downGrade(int amount)
{
	if (this->_grade + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += amount;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Grade Too High Exception]: Grade must be between 1 and 150");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Grade Too Low Exception]: Grade must be between 1 and 150");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();

	return out;
}

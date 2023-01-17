/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:31:24 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 18:36:22 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(""), _signed(false)
{
}

Form::Form(const std::string &name, int grade_sign, int grade_exe):
	_name(name), _signed(false), _grade_sign(grade_sign), _grade_exe(grade_exe)
{
}

Form::Form(const Form &copy):
	_grade_sign(copy._grade_sign), _grade_exe(copy._grade_exe)
{
	*this = copy;
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

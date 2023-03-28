/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:03:47 by aperin            #+#    #+#             */
/*   Updated: 2023/03/28 11:46:23 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice &copy)
{
	(void) copy;
	this->_type = "ice";
}

Ice::~Ice()
{
}

Ice	&Ice::operator=(const Ice &copy)
{
	(void) copy;
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

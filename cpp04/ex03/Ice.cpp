/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:03:47 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 13:45:52 by aperin           ###   ########.fr       */
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
	*this = copy;
}

Ice::~Ice()
{
}

Ice	&Ice::operator=(const Ice &copy)
{
	this->_type = copy._type;

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

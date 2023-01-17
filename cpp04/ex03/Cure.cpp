/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:40 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 15:04:11 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure &copy)
{
	*this = copy;
}

Cure::~Cure()
{
}

Cure	&Cure::operator=(const Cure &copy)
{
	this->_type = copy._type;

	return *this;
}

AMateria	*Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

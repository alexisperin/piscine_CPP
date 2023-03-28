/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:40 by aperin            #+#    #+#             */
/*   Updated: 2023/03/28 11:46:07 by aperin           ###   ########.fr       */
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
	(void) copy;
	this->_type = "cure";
}

Cure::~Cure()
{
}

Cure	&Cure::operator=(const Cure &copy)
{
	(void) copy;
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

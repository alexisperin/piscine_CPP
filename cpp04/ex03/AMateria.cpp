/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:57:58 by aperin            #+#    #+#             */
/*   Updated: 2023/03/28 11:11:19 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(const std::string &type)
{
	this->_type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria::~AMateria()
{
}

AMateria	&AMateria::operator=(const AMateria &copy)
{
	(void) copy;
	return *this;
}

const std::string	&AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* " << this->_type << " used on " << target.getName()
		<< " *\n";
}

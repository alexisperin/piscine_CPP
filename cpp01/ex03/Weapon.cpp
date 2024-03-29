/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:58:32 by aperin            #+#    #+#             */
/*   Updated: 2023/01/06 16:56:10 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType()
{
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

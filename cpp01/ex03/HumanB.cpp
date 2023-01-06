/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:06:25 by aperin            #+#    #+#             */
/*   Updated: 2023/01/06 17:20:22 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "iostream"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	std::cout << "HumanB " << name << " created with no weapon\n";
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed\n";
}

void	HumanB::attack() const
{
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:50:39 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 13:35:50 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy),
	FragTrap(copy)
{
	this->_name = copy._name;
	this->_hit = copy._hit;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &copy)
{
	this->_name = copy._name;
	this->_hit = copy._hit;
	this->_energy = copy._energy;
	this->_attack = copy._attack;

	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is "
		<< ClapTrap::_name << std::endl;
}

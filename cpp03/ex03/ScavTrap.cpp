/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:11:56 by aperin            #+#    #+#             */
/*   Updated: 2023/03/22 11:53:55 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->_name = copy._name;
	this->_hit = copy._hit;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap	&ScavTrap::operator=(ScavTrap &copy)
{
	this->_name = copy._name;
	this->_hit = copy._hit;
	this->_energy = copy._energy;
	this->_attack = copy._attack;

	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is in gate keeper mode\n";
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy < 1)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy !\n";
		return ;
	}
	if (this->_hit < 1)
	{
		std::cout << "ScavTrap " << this->_name << " is dead !\n";
		return ;
	}
	this->_energy--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< " causing " << this->_attack << " damage\n";
}

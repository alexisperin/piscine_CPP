/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:11:56 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 09:22:21 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ClapTrap default constructor called\n";
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:56:30 by aperin            #+#    #+#             */
/*   Updated: 2023/01/13 16:15:37 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): _name(""), _hit(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy): _name(copy._name), _hit(copy._hit),
								_energy(copy._energy), _attack(copy._attack)
{
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hit(10),
										_energy(10), _attack(0)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap	&ClapTrap::operator=(ClapTrap &copy)
{
	this->_name = copy._name;
	this->_hit = copy._hit;
	this->_energy = copy._energy;
	this->_attack = copy._attack;

	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy < 1)
	{
		std::cout << this->_name << " is out of energy !\n";
		return ;
	}
	if (this->_hit < 1)
	{
		std::cout << this->_name << " is dead !\n";
		return ;
	}
	this->_energy--;
	std::cout << this->_name << " attacks " << target << " causing "
		<< this->_attack << " damage\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " takes " << amount << " damage\n";
	if (amount > this->_hit)
	{
		this->_hit = 0;
		std::cout << this->_name << " is dead\n";
	}
	else
		this->_hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy < 1)
	{
		std::cout << this->_name << " is out of energy !\n";
		return ;
	}
	this->_energy--;
	this->_hit += amount;
	std::cout << this->_name << " repaires " << amount << " points\n";
}

std::string	ClapTrap::getName() const
{
	return this->_name;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->_attack;
}

void	ClapTrap::setAttack(unsigned int amount)
{
	std::cout << this->_name << " sets attack to " << amount << std::endl;
	this->_attack = amount;
}

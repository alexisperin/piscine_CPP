/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:11:56 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 11:20:55 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	this->_name = copy._name;
	this->_hit = copy._hit;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap	&FragTrap::operator=(FragTrap &copy)
{
	this->_name = copy._name;
	this->_hit = copy._hit;
	this->_energy = copy._energy;
	this->_attack = copy._attack;

	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "High fives brothers !\n";
}

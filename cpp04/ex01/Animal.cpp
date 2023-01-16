/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:00:35 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 16:56:06 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	this->_type = "Some animal";
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called\n";
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal	&Animal::operator=(const Animal &copy)
{
	this->_type = copy._type;
	std::cout << "Animal assignment operator called\n";

	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "I'm an animal\n";
}

std::string	Animal::getType() const
{
	return this->_type;
}

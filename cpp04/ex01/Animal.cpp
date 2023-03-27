/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:00:35 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 17:53:22 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal default constructor called\n";
	this->_type = "Some animal";
	this->_brain = new Brain();
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called\n";
	this->_brain = new Brain();
	*this = copy;
}

Animal::~Animal()
{
	delete this->_brain;
	std::cout << "Animal destructor called\n";
}

Animal	&Animal::operator=(const Animal &copy)
{
	this->_type = copy._type;
	*(this->_brain) = *(copy._brain);
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

void	Animal::addIdea(const std::string &idea)
{
	this->_brain->addIdea(idea);
}

std::string	Animal::getIdea(unsigned int index) const
{
	return this->_brain->getIdea(index);
	
}

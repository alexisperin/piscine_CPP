/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:20:55 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 19:39:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called\n";
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	std::cout << "Dog copy constructor called\n";
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete this->_brain;
}

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignment operator called\n";
	this->_type = copy._type;
	*(this->_brain) = *(copy._brain);

	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf wouf\n";
}

void	Dog::addIdea(const std::string &idea)
{
	this->_brain->addIdea(idea);
}

std::string	Dog::getIdea(unsigned int index) const
{
	return this->_brain->getIdea(index);
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:46:15 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 19:39:07 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called\n";
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat copy constructor called\n";
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignment operator called\n";
	this->_type = copy._type;
	*(this->_brain) = *(copy._brain);

	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaow miaow\n";
}

void	Cat::addIdea(const std::string &idea)
{
	this->_brain->addIdea(idea);
}

std::string	Cat::getIdea(unsigned int index) const
{
	return this->_brain->getIdea(index);
	
}

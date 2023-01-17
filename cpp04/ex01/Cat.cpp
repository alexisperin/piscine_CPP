/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:46:15 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 08:48:57 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat copy constructor called\n";
	this->_brain = new Brain();
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat &copy)
{
	this->_type = copy._type;
	*(this->_brain) = *(copy._brain);
	std::cout << "Cat assignment operator called\n";

	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaow miaow\n";
}
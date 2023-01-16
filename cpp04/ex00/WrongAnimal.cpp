/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:50:11 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 16:55:47 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	this->_type = "Some wrong animal";
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called\n";
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->_type = copy._type;
	std::cout << "WrongAnimal assignment operator called\n";

	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "I'm an WrongAnimal\n";
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}

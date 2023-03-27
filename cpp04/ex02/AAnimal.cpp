/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:00:35 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 21:08:03 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called\n";
	this->_type = "Some Aanimal";
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called\n";
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal assignment operator called\n";
	this->_type = copy._type;

	return *this;
}

void	AAnimal::makeSound() const
{
	std::cout << "I'm an Aanimal\n";
}

std::string	AAnimal::getType() const
{
	return this->_type;
}

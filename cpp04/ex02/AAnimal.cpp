/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:00:35 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 19:30:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	this->_type = "Some Aanimal";
	std::cout << "AAnimal default constructor called\n";
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
	this->_type = copy._type;
	std::cout << "AAnimal assignment operator called\n";

	return *this;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}

void	AAnimal::addIdea(const std::string &idea)
{
	this->_brain->addIdea(idea);
}

std::string	AAnimal::getIdea(unsigned int index) const
{
	return this->_brain->getIdea(index);
}

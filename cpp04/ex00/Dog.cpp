/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:20:55 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 16:20:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	std::cout << "Dog copy constructor called\n";
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog	&Dog::operator=(const Dog &copy)
{
	this->_type = copy._type;
	std::cout << "Dog assignment operator called\n";

	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf wouf\n";
}

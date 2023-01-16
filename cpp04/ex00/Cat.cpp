/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:46:15 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 16:20:44 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat copy constructor called\n";
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat	&Cat::operator=(const Cat &copy)
{
	this->_type = copy._type;
	std::cout << "Cat assignment operator called\n";

	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaow miaow\n";
}

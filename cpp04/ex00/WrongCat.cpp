/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:51:15 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 16:54:28 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	this->_type = copy._type;
	std::cout << "WrongCat assignment operator called\n";

	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaow miaow\n";
}

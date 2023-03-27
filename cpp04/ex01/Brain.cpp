/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:28:14 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 11:54:56 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	this->_index = 0;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Brain copy constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain	&Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assignment operator called\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	this->_index = copy._index;

	return *this;
}

void	Brain::addIdea(const std::string &idea)
{
	this->_ideas[this->_index] = idea;
	this->_index++;
	if (this->_index == 100)
		this->_index = 0;
}

std::string	Brain::getIdea(unsigned int index) const
{
	if (index >= 0 && index <= 99)
		return this->_ideas[index];
	return std::string();
}

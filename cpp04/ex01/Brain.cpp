/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:28:14 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 17:35:22 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
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
	this->_ideas = copy._ideas;
	std::cout << "Brain assignment operator called\n";
}

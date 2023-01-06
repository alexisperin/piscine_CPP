/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:34:32 by aperin            #+#    #+#             */
/*   Updated: 2023/01/06 14:42:28 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << name << " created\n";
}

Zombie::~Zombie()
{
	std::cout << this->_name << " destroyed\n";
}

void	Zombie::announce()
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ...\n";
}

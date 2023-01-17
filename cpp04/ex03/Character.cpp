/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:35:16 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 14:08:25 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_materials[i] = NULL;
}

Character::Character(const std::string &name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materials[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->_materials[i];
}

Character	&Character::operator=(const Character &copy)
{
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._materials[i])
		{
			delete this->_materials[i];
			this->_materials[i] = copy._materials[i]->clone();
		}
		else
			this->_materials[i] = NULL;
	}
	return *this;
}

const std::string	&Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materials[i] == NULL)
		{
			this->_materials[i] = m;
			break;
		}
	}
}

void	Character::unequip(int index)
{
	if (index >= 0 && index <= 3)
		this->_materials[index] = NULL;
}

void	Character::use(int index, ICharacter &target)
{
	if (index >= 0 && index <= 3 && this->_materials[index] != NULL)
		this->_materials[index]->use(target);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:15:23 by aperin            #+#    #+#             */
/*   Updated: 2023/03/28 11:49:10 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	IMateriaSource*	source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	ICharacter*	man = new Character("man");
	AMateria*	temp;
	temp = source->createMateria("icing cake");
	man->equip(temp);
	temp = source->createMateria("cure");
	man->equip(temp);

	ICharacter*	bobby = new Character("bobby");
	man->use(0, *bobby);
	man->use(1, *bobby);

	man->unequip(0);
	man->use(0, *bobby);

	delete temp;
	delete bobby;
	delete man;
	delete source;

	return 0;
}

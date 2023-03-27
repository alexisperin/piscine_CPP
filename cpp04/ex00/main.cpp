/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:09:49 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 17:41:34 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "Testing WrongCat and WrongAnimal\n\n";

	const WrongAnimal* w_animal = new WrongAnimal();
	const WrongAnimal* w_cat = new WrongCat();
	std::cout << std::endl;

	std::cout << w_animal->getType() << " " << std::endl;
	std::cout << w_cat->getType() << " " << std::endl;
	std::cout << std::endl;

	w_animal->makeSound();
	w_cat->makeSound();
	std::cout << std::endl;

	delete w_animal;
	delete w_cat;
	std::cout << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:09:49 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 11:57:33 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	Animal	*animals[4];

	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	std::cout << std::endl;

	animals[0]->addIdea("This is so boring");
	Dog	copy(*(Dog *) animals[0]);
	animals[0]->addIdea("This is sooooooooooooooooo boring");
	std::cout << animals[0]->getIdea(1) << std::endl;
	std::cout << copy.getIdea(1) << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	std::cout << std::endl;
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:09:49 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 09:09:38 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	AAnimal	*animals[4];

	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	std::cout << std::endl;

	animals[0]->addIdea("This is so boring");
	Dog	copy(*(Dog *) animals[0]);
	std::cout << copy.getIdea(0) << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	std::cout << std::endl;

	// AAnimal a;
	
	return 0;
}

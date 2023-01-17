/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:18:44 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 09:05:42 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog: public AAnimal
{
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog	&operator=(const Dog &copy);

		virtual void	makeSound() const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:53 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 19:30:12 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		//Assignment operator
		Animal	&operator=(const Animal &copy);

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif

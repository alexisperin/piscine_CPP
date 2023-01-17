/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:53 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 19:30:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	_type;
		Brain		*_brain;

	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		//Assignment operator
		Animal	&operator=(const Animal &copy);

		virtual void	makeSound() const;
		std::string		getType() const;
		void			addIdea(const std::string &idea);
		std::string		getIdea(unsigned int) const;
};

#endif
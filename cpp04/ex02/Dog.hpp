/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:18:44 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 21:08:31 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog	&operator=(const Dog &copy);

		virtual void	makeSound() const;
		void			addIdea(const std::string &idea);
		std::string		getIdea(unsigned int index) const;
};

#endif

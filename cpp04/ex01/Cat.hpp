/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:47:31 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 19:31:04 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat	&operator=(const Cat &copy);

		virtual void	makeSound() const;
		void			addIdea(const std::string &idea);
		std::string		getIdea(unsigned int index) const;
};

#endif

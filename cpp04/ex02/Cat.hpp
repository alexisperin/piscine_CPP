/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:47:31 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 09:05:11 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat: public AAnimal
{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat	&operator=(const Cat &copy);

		virtual void	makeSound() const;
};

#endif

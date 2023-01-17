/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:53 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 09:04:59 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	_type;
		Brain		*_brain;

	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		//Assignment operator
		AAnimal	&operator=(const AAnimal &copy);

		virtual void	makeSound() const = 0;
		std::string		getType() const;
		void			addIdea(const std::string &idea);
		std::string		getIdea(unsigned int) const;
};

#endif

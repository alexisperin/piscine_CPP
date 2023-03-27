/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:53 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 21:07:34 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		//Assignment operator
		AAnimal	&operator=(const AAnimal &copy);

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif

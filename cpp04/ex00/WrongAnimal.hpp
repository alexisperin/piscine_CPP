/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:47:15 by aperin            #+#    #+#             */
/*   Updated: 2023/03/27 10:36:25 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();

		//Assignment operator
		WrongAnimal	&operator=(const WrongAnimal &copy);

		void		makeSound() const;
		std::string	getType() const;
};

#endif

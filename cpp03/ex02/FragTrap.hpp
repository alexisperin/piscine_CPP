/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:11:58 by aperin            #+#    #+#             */
/*   Updated: 2023/03/22 12:19:05 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		//Constructor/destructor
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

		//Assignment operator
		FragTrap	&operator=(FragTrap &copy);

		//Member functions
		void			highFivesGuys();
};

#endif

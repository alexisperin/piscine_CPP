/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:11:58 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 10:37:44 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
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
		void	highFivesGuys();
};

#endif

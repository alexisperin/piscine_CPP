/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:11:58 by aperin            #+#    #+#             */
/*   Updated: 2023/03/22 12:24:02 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		//Constructor/destructor
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		//Assignment operator
		ScavTrap	&operator=(ScavTrap &copy);

		//Member functions
		void	attack(const std::string &target);
		void	guardGate();
};

#endif

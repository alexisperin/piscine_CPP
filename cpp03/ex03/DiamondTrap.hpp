/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:33:01 by aperin            #+#    #+#             */
/*   Updated: 2023/03/22 12:22:58 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(DiamondTrap &copy);
		~DiamondTrap();

		//Assignment operator
		DiamondTrap	&operator=(DiamondTrap &copy);

		//Member functions
		void	whoAmI();
		using ScavTrap::attack;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:46:43 by aperin            #+#    #+#             */
/*   Updated: 2023/01/13 16:07:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;

	public:
		//Constructor/destructor
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(const std::string &name);
		~ClapTrap();

		//Assignment operator
		ClapTrap	&operator=(ClapTrap &copy);

		//Member functions
		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName() const;
		unsigned int	getAttackDamage() const;
		void			setAttack(unsigned int amount);
};

#endif

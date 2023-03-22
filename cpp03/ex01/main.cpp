/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:55:22 by aperin            #+#    #+#             */
/*   Updated: 2023/03/22 11:48:38 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a("a");
	ScavTrap	b("b");
	ClapTrap	c("c");

	a.guardGate();
	b.attack("a");
	a.takeDamage(b.getAttackDamage());
	c.attack("a");

	return 0;
}

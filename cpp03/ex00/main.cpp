/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:55:22 by aperin            #+#    #+#             */
/*   Updated: 2023/01/13 16:08:08 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	michel("Michel");
	ClapTrap	claude("Claude");

	michel.setAttack(3);
	michel.attack(claude.getName());
	claude.takeDamage(michel.getAttackDamage());
	michel.beRepaired(5);

	return 0;
}

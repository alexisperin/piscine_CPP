/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:55:22 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 09:02:29 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	michel("Michel");
	ScavTrap	claude("Claude");

	michel.guardGate();
	claude.attack("Michel");
	michel.takeDamage(claude.getAttackDamage());

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:55:22 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 13:43:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap	michel("Michel");
	DiamondTrap	claude("Claude");
	std::cout << std::endl;

	claude.attack("Michel");
	michel.takeDamage(claude.getAttackDamage());
	std::cout << std::endl;

	michel.setAttack(100);
	DiamondTrap	danny(michel);
	danny.attack("Claude");
	claude.takeDamage(danny.getAttackDamage());
	std::cout << std::endl;

	michel.whoAmI();
	claude.whoAmI();
	danny.whoAmI();
	std::cout << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:55:22 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 10:26:32 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap	michel("Michel");
	FragTrap	claude("Claude");

	michel.highFivesGuys();
	claude.attack("Michel");
	michel.takeDamage(claude.getAttackDamage());

	return 0;
}

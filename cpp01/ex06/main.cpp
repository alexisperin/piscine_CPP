/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:34:33 by aperin            #+#    #+#             */
/*   Updated: 2023/01/11 10:59:26 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	ft_switch(std::string level)
{
	std::string	levels[] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return i;
	}
	return -1;
}

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "I am not sure how tired I am today...\n";
		return 1;
	}
	switch (ft_switch(av[1]))
	{
		case 0:
			harl.complain("debug");
		case 1:
			harl.complain("info");
		case 2:
			harl.complain("warning");
		case 3:
			harl.complain("error");
			break;
		default:
			std::cout << "I am not sure how tired I am today...\n";
			break;
	}
}

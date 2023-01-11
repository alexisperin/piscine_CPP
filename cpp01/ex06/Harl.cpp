/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:43:22 by aperin            #+#    #+#             */
/*   Updated: 2023/01/11 11:01:08 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	std::cout << "Harl created\n";
}

Harl::~Harl()
{
	std::cout << "Harl destroyed\n";
}

void	Harl::_debug()
{
	std::cout << "[DEBUG]: I love having bacon for my 7XL-double-cheese" \
		<< "-triple-pickel-special-ketchup burger. I really do !\n";
}

void	Harl::_info()
{
	std::cout << "[INFO]: I cannot believe adding bacon costs more money." \
		<< " You didn't put enough bacon in my burger !" \
		<< " If you did, I wouldn't be asking for more !\n";
}

void	Harl::_warning()
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for" \
		<< " free. I've been coming for years whereas you started working" \
		<< " here since last month.\n";
}

void	Harl::_error()
{
	std::cout << "[ERROR]: This is unacceptable ! I want to speak to the" \
		<< " manager now !\n";
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"debug", "info", "warning", "error"};
	void	(Harl::*ptr[4])(void) = {&Harl::_debug, &Harl::_info,
				&Harl::_warning, &Harl::_error};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*ptr[i])();
			break;
		}
	}
}

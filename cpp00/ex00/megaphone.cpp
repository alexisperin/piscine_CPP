/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:37:52 by aperin            #+#    #+#             */
/*   Updated: 2023/01/03 14:59:38 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

char ft_toupper(char c)
{
	return ((c >= 97 && c <= 122) ? c - 32 : c);
}

int main(int ac, char **av)
{
    if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			int len = strlen(av[i]);
			for (int j = 0; j < len; j++)
				std::cout << ft_toupper(av[i][j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}

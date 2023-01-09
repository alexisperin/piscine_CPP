/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:25:15 by aperin            #+#    #+#             */
/*   Updated: 2023/01/09 16:45:59 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void	ft_replace(std::ifsteam file, new_file, std::string(av[2]), std::string(av[1]),
			std::string(av[2]))

int	main(int ac, char **av)
{
	std::ifstream	file;
	std::ofstream	new_file;

	if (ac != 4)
		std::cout << "Wrong amount of arguments\n";
	else
	{
		file.open(av[1], std::ios::in);
		if (!file.is_open())
		{
			std::cout << av[1] << ": no such file or directory\n";
			return 1;
		}
		new_file.open(std::string(av[1]) + ".replace", std::ios::out);
		if (!new_file.is_open())
		{
			std::cout << av[1] << ".replace not created\n";
			file.close();
			return 1;
		}
		ft_replace(file, new_file, std::string(av[2]), std::string(av[1]),
			std::string(av[2]));
		file.close();
		new_file.close();
	}
	return 0;
}

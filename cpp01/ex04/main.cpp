/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:25:15 by aperin            #+#    #+#             */
/*   Updated: 2023/01/10 16:11:12 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	ft_replace(char **av, std::string &src)
{
	std::ofstream	new_file;

	new_file.open((std::string(av[1]) + ".replace").c_str(), std::ios::out);
	if (!new_file.is_open())
	{
		std::cout << av[1] << ".replace not created\n";
		return 1;
	}
	for (size_t i = 0; src[i]; i++)
	{
		if (src.find(av[2], i) == i)
		{
			new_file << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			new_file << src[i];
	}
	new_file.close();
	return 0;
}

int	main(int ac, char **av)
{
	std::ifstream	file;
	std::string		src;
	char			c;

	if (ac != 4)
	{
		std::cout << "Wrong amount of arguments\n";
		return 1;
	}
	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cout << av[1] << ": no such file or directory\n";
		return 1;
	}
	while (!file.eof() && file >> std::noskipws >> c)
		src += c;
	file.close();
	return ft_replace(av, src);
}

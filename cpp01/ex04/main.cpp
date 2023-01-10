/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:25:15 by aperin            #+#    #+#             */
/*   Updated: 2023/01/10 14:38:07 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

// int	ft_replace(std::ifstream file, std::string src, std::string s1,
// 				std::string s2)
// {
// 	std::ofstream	new_file;

// 	new_file.open(std::string(av[1]) + ".replace", std::ios::out);
// 	if (!new_file.is_open())
// 	{
// 		std::cout << av[1] << ".replace not created\n";
// 		file.close();
// 		return 1;
// 	}
// }

// int	main(int ac, char **av)
// {
// 	std::ifstream	file;
// 	std::string		src;
// 	std::string		tmp;

// 	if (ac != 4)
// 	{
// 		std::cout << "Wrong amount of arguments\n";
// 		return 1;
// 	}
// 	file.open(av[1], std::ios::in);
// 	if (!file.is_open())
// 	{
// 		std::cout << av[1] << ": no such file or directory\n";
// 		return 1;
// 	}
// 	std::getline(file, src);
// 	while (file.eof())
// 	{
// 		src += "\n";
// 		std::getline(file, tmp);
// 		src += tmp;
// 	}
// 	std::cout << src << std::endl;
// 	file.close();
// 	// new_file.close();
// 	return 0;
// }

#include <fstream>
#include <iostream>

int	replace(char **argv, std::string str)
{
	std::ofstream	outfile;
	int				pos;

	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(argv[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	char			c[16];
	std::ifstream	infile;
	std::string		str;

	if (argc != 4)
	{
		std::cout << "usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "Error: " << argv[1] << ":" << \
		" no such file or directory" << std::endl;
		return (1);
	}
	while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	std::cout << str;
	return (replace(argv, str));
}

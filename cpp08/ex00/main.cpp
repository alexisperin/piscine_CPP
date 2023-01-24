/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:41:01 by aperin            #+#    #+#             */
/*   Updated: 2023/01/24 10:54:20 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <list>

int main()
{
	std::cout << "---Array---\n";
	std::array<int, 10> arr;
	for (int i = 0; i < 10; i++)
		arr[i] = i;

	try
	{
		easyfind(arr, 4);
		easyfind(arr, 15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---List---\n";
	std::list<int> list;
	for (int i = 0; i < 10; i++)
		list.push_back(i);

	try
	{
		easyfind(list, 9);
		easyfind(list, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

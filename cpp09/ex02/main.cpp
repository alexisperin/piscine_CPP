/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:14:15 by aperin            #+#    #+#             */
/*   Updated: 2023/04/17 13:15:39 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <sys/time.h>

static void sorted(std::vector<int> &vector)
{
	for (unsigned int i = 0; i < vector.size() - 1; i++)
	{
		if (vector[i] > vector[i + 1])
		{
			std::cout << "NOT SORTED\n";
			return ;
		}
	}
}

static bool get_numbers(std::vector<int> &vector, std::deque<int> &deque,
	int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (!isdigit(av[i][j]))
			{
				std::cout << "Error: " << av[i] << ": invalid input\n";
				return false;
			}
		}
		std::istringstream	iss(av[i]);
		std::istringstream	iss2(av[i]);
		int		n;
		long	l;
		iss >> n;
		iss2 >> l;
		if (n != l || n < 0)
		{
			std::cout << "Error: " << av[i] << ": invalid number\n";
			return false;
		}
		vector.push_back(n);
		deque.push_back(n);
	}
	return true;
}

int main(int ac , char **av)
{
	struct timeval begin, end;

	if (ac < 2)
		return 0;
	std::vector<int> vector;
	std::deque<int> deque;
	if (get_numbers(vector, deque, ac, av))
	{
		std::cout << "Before: ";
		for (unsigned int i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
		std::cout << std::endl;
		gettimeofday(&begin, 0);
		merge_insert_sort_vector(vector);
		gettimeofday(&end, 0);
		std::cout << "After: ";
		for (unsigned int i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
		std::cout << std::endl;
		std::cout << "Time to process a range of " << vector.size()
			<< " elements with std::vector : " << end.tv_usec - begin.tv_usec
			<< " us\n";
		gettimeofday(&begin, 0);
		merge_insert_sort_deque(deque);
		gettimeofday(&end, 0);
		std::cout << "Time to process a range of " << deque.size()
			<< " elements with std::deque : " << end.tv_usec - begin.tv_usec
			<< " us\n";
		sorted(vector);
	}
}

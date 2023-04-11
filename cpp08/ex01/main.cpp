/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:56:41 by aperin            #+#    #+#             */
/*   Updated: 2023/04/11 17:01:01 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	srand(time(NULL));

	std::cout << "---TEST 1---\n";
	{
		Span	span(10000);

		try
		{
			for (int i = 0; i < 10000; i++)
				span.addNumber(rand() % 10000);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << span << std::endl;
		try
		{
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << "\n\n---TEST 2---\n";
	{
		Span	span(10);

		try
		{
			for (int i = 0; i < 10; i++)
				span.addNumber(rand() % 100);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << span << std::endl;
		try
		{
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << "\n\n---TEST 3---\n";
	{
		Span	span(10);

		try
		{
			for (int i = 0; i < 1; i++)
				span.addNumber(rand() % 100);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << span << std::endl;
		try
		{
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\n\n---TEST 4---\n";
	{
		Span	span(10);

		try
		{
			for (int i = 0; i < 5; i++)
				span.addNumber(rand() % 100);
			span.addNumbers(span.begin(), span.end());
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << span << std::endl;
		try
		{
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return 0;
}

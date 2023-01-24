/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:57:48 by aperin            #+#    #+#             */
/*   Updated: 2023/01/24 14:20:34 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

Span::Span(): _N(0)
{
}

Span::Span(const unsigned int N): _N(N)
{
}

Span::Span(const Span &copy): _N(copy._N)
{
	*this = copy;
}

Span::~Span()
{
}

Span	&Span::operator=(const Span &copy)
{
	this->_numbers = copy._numbers;

	return *this;
}

void	Span::addNumber(int n)
{
	if (this->_numbers.size() >= this->_N)
		throw Span::NoSpaceLeftInSpanException();
	this->_numbers.push_back(n);
}

unsigned int	Span::shortestSpan() const
{
	std::list<unsigned int>	distances;
	std::list<int>::const_iterator	iter;
	for (iter = this->_numbers.begin(); iter != this->_numbers.end(); ++iter)
	{
		std::list<int>::const_iterator	iter2 = iter;
		++iter2;
		while (iter2 != this->_numbers.end())
		{
			distances.push_back(abs(*iter - *iter2));
			++iter2;
		}
	}
	return *std::min_element(distances.begin(), distances.end());
}

unsigned int	Span::longestSpan() const
{
	std::list<unsigned int>	distances;
	std::list<int>::const_iterator	iter;
	for (iter = this->_numbers.begin(); iter != this->_numbers.end(); ++iter)
	{
		std::list<int>::const_iterator	iter2 = iter;
		++iter2;
		while (iter2 != this->_numbers.end())
		{
			distances.push_back(abs(*iter - *iter2));
			++iter2;
		}
	}
	return *std::max_element(distances.begin(), distances.end());
}

std::list<int>::const_iterator	Span::begin() const
{
	return this->_numbers.begin();
}

std::list<int>::const_iterator	Span::end() const
{
	return this->_numbers.end();
}

const char	*Span::NoSpaceLeftInSpanException::what() const throw()
{
	return "[NoSpaceLeftInSpanException]";
}

const char	*Span::NoSpanFoundException::what() const throw()
{
	return "[NoSpanFoundException]";
}

std::ostream	&operator<<(std::ostream &out, const Span &span)
{
	std::list<int>::const_iterator	iter;
	for (iter = span.begin(); iter != span.end(); ++iter)
		out << *iter << " ";

	return out;
}

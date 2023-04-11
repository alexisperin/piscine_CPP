/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:57:48 by aperin            #+#    #+#             */
/*   Updated: 2023/04/11 17:00:32 by aperin           ###   ########.fr       */
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

void	Span::addNumbers(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
	if (this->_numbers.size() >= this->_N)
		throw Span::NoSpanFoundException();
	this->_numbers.insert(this->_numbers.end(), begin, end);
}

unsigned int	Span::shortestSpan() const
{
	unsigned int	min;
	std::list<int>::const_iterator	iter;
	std::list<int>::const_iterator	end = this->_numbers.end();

	if (this->_numbers.size() < 2)
		throw Span::NoSpanFoundException();
	min = abs(*(this->_numbers.begin()) - *(++this->_numbers.begin()));
	for (iter = this->_numbers.begin(); iter != end; ++iter)
	{
		std::list<int>::const_iterator	iter2 = iter;
		++iter2;
		while (iter2 != end)
		{
			if (min > (unsigned int) abs(*iter - *iter2))
				min = abs(*iter - *iter2);
			++iter2;
		}
	}
	return min;
}

unsigned int	Span::longestSpan() const
{
	unsigned int	max;
	std::list<int>::const_iterator	iter;
	std::list<int>::const_iterator	end = this->_numbers.end();

	if (this->_numbers.size() < 2)
		throw Span::NoSpanFoundException();
	for (iter = this->_numbers.begin(); iter != end; ++iter)
	{
		std::list<int>::const_iterator	iter2 = iter;
		++iter2;
		while (iter2 != end)
		{
			if (max < (unsigned int) abs(*iter - *iter2))
				max = abs(*iter - *iter2);
			++iter2;
		}
	}
	return max;
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

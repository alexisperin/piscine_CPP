/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:57:46 by aperin            #+#    #+#             */
/*   Updated: 2023/04/11 16:46:24 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <list>
# include <iostream>

class Span
{
	private:
		const unsigned int	_N;
		std::list<int>	_numbers;

		Span();
		Span	&operator=(const Span &copy);

	public:
		Span(const unsigned int N);
		Span(const Span &copy);
		~Span();

		void	addNumber(int n);
		void	addNumbers(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		std::list<int>::const_iterator	begin() const;
		std::list<int>::const_iterator	end() const;
		
		class NoSpaceLeftInSpanException: public std::exception
		{
			public:
				const char	*what() const throw();					
		};

		class NoSpanFoundException: public std::exception
		{
			public:
				const char	*what() const throw();					
		};
};

std::ostream	&operator<<(std::ostream &out, const Span &span);

#endif

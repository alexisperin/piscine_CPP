/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:57:46 by aperin            #+#    #+#             */
/*   Updated: 2023/01/24 14:17:01 by aperin           ###   ########.fr       */
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

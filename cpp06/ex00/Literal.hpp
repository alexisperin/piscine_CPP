/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:47:30 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 09:45:56 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <string>

class Literal
{
	private:
		const std::string	_s;

		void	_toType();
		void	_toChar();
		void	_toInt();
		void	_toFloat();
		void	_toDouble();

	public:
		Literal();
		Literal(const std::string input);
		Literal(const Literal &copy);
		~Literal();
		Literal	&operator=(const Literal &copy);
};

#endif

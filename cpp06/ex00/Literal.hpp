/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:47:30 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 09:19:50 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <string>

class Literal
{
	private:
		const std::string	_s;
		int					_flags[] = {1, 1, 1, 1};
		char				_c;
		int					_i;
		float				_f;
		double				_d;

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

		void	displayLiteral() const;
};

#endif

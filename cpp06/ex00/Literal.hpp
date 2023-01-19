/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:47:30 by aperin            #+#    #+#             */
/*   Updated: 2023/01/19 11:17:46 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <string>

class Literal
{
	private:
		const std::string	_s;
		char				_c;
		int					_i;
		float				_f;
		double				_d;

		int	_getType() const;

	public:
		Literal();
		Literal(const std::string input);
		Literal(const Literal &copy);
		~Literal();
		Literal	&operator=(const Literal &copy);

		char	toChar() const;
		int		toInt() const;
		float	toFloat() const;
		double	toDouble() const;
		void	displayLiteral() const;
};

#endif

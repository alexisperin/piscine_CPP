/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:30:02 by aperin            #+#    #+#             */
/*   Updated: 2023/04/14 21:02:10 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>

class RPN
{
	private:
		std::string	_str;
		bool		_error;

		RPN();
		RPN(const RPN &copy);
		RPN	&operator=(const RPN &copy);
		int	_compute(int n1, int n2, char c);

	public:
		RPN(const std::string &str);
		~RPN();
		void	setSequence(const std::string &str);
		void	execute();
};

#endif

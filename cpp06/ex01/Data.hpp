/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:41:39 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 13:52:57 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		int	_a;
		int	_b;

	public:
		Data();
		Data(const Data &copy);
		~Data();
		Data	&operator=(const Data &copy);

		int	getA() const;
		int	getB() const;
};

std::ostream	&operator<<(std::ostream &out, const Data &data);

#endif

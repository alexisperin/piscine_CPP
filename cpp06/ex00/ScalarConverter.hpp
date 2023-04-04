/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:27 by aperin            #+#    #+#             */
/*   Updated: 2023/04/04 09:38:55 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
		static void	_toChar(std::string str);
		static void	_toInt(std::string str);
		static void	_toFloat(std::string str);
		static void	_toDouble(std::string str);

		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &copy);

	public:
		static void	convert(std::string str);
};

#endif

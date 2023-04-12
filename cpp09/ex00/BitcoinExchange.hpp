/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:40:30 by aperin            #+#    #+#             */
/*   Updated: 2023/04/12 16:12:33 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define WHITESPACES " \n\r\t\f\v"

# include <map>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_map;

		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange	&operator=(const BitcoinExchange &copy);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	process_input(const std::string &filename);
		void	print_map();
};

#endif

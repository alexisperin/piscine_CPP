/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:40:30 by aperin            #+#    #+#             */
/*   Updated: 2023/04/13 10:35:47 by aperin           ###   ########.fr       */
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

		std::string	_parse_date(std::string &str, size_t pos);
		float		_parse_number(std::string &str, size_t pos);
		bool		_valid_date(const std::string &date);
		bool		_valid_number(const std::string &number);
		void		_find_rate(std::string &date, float value);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	process_input(const std::string &filename);
		void	print_map();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:51:18 by aperin            #+#    #+#             */
/*   Updated: 2023/01/05 08:41:01 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		_contacts[8];
		int			_index;
		int			_nb_contacts;

		std::string	_read_info() const;
		void		_print_str(std::string str) const;
	
	public:
		// Constructor/destructor
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;
};

#endif

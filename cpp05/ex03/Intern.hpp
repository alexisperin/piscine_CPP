/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:46:39 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 15:31:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern	&operator=(const Intern &copy);

		AForm	*makeForm(const std::string &name, const std::string &target);

		class UnknownFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif

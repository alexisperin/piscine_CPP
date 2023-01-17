/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:09:07 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 19:30:25 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string		_ideas[100];
		unsigned int	_index;

	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain	&operator=(const Brain &copy);

		void		addIdea(const std::string &idea);
		std::string	getIdea(unsigned int) const;
};

#endif

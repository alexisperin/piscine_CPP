/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:09:07 by aperin            #+#    #+#             */
/*   Updated: 2023/01/16 17:12:43 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain	&operator=(const Brain &copy);
}:

#endif

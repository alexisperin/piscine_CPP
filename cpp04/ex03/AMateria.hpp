/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:12:27 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 09:15:29 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
	protected:
		

	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &copy);
		AMateria	&operator=(const AMateria &copy);

		const std::string	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif

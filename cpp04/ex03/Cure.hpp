/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:14 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 11:31:38 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure &operator=(const Cure &copy);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif

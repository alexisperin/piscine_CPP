/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:36:49 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 13:43:54 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_materials[4];

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		virtual			~Character();
		Character		&operator=(const Character &copy);

		virtual std::string	const & getName() const;
		virtual void		equip(AMateria *m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter &target);
};

#endif

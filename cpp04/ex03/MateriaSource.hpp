/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:58:14 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 14:46:28 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_materials[4];
		
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		virtual ~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &copy);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria	*createMateria(const std::string &type);
};

#endif

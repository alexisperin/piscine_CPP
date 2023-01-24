/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:25:47 by aperin            #+#    #+#             */
/*   Updated: 2023/01/24 14:57:43 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>(){};
		MutantStack<T>(const MutantStack<T> &copy): std::stack<T>(copy){};
		~MutantStack(){std::stack<T>::~stack();};
		MutantStack<T>	&operator=(const MutantStack &copy)
		{
			std::stack<T>::operator=(copy);
			return *this;
		}

		
};

#endif

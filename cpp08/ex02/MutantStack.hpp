/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:25:47 by aperin            #+#    #+#             */
/*   Updated: 2023/01/24 17:06:52 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack<T>(): std::stack<T>(){};
		MutantStack<T>(const MutantStack<T> &copy): std::stack<T>(copy){};
		~MutantStack<T>(){};
		MutantStack<T>	&operator=(const MutantStack &copy)
		{
			std::stack<T>::operator=(copy);
			return *this;
		}

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator	begin()
		{
			return this->c.begin();
		}

		iterator	end()
		{
			return this->c.end();
		}

		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		const_iterator	cbegin() const
		{
			return this->c.cbegin();
		}

		const_iterator	cend() const
		{
			return this->c.cend();
		}

		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		typename MutantStack<T>::reverse_iterator	rbegin()
		{
			return this->c.rbegin();
		}

		typename MutantStack<T>::reverse_iterator	rend()
		{
			return this->c.rend();
		}

		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		typename MutantStack<T>::const_reverse_iterator	crbegin() const
		{
			return this->c.rbegin();
		}

		typename MutantStack<T>::const_reverse_iterator	crend() const
		{
			return this->c.crend();
		}
};

#endif

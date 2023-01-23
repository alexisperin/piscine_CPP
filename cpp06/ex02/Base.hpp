/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:32:24 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 15:42:37 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base(){};
};

class A: public Base
{
	public:
		A(){};
		~A(){};
		void	print_type();
};

class B: public Base
{
	public:
		B(){};
		~B(){};
		void	print_type();
};

class C: public Base
{
	public:
		C(){};
		~C(){};
		void	print_type();
};

#endif

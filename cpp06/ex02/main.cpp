/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:44:51 by aperin            #+#    #+#             */
/*   Updated: 2023/04/03 17:27:24 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>

Base	*generate()
{
	srand(time(NULL));
	int	n = rand() % 3;

	switch (n)
	{
	case 0:
		return static_cast<Base *>(new A());
	case 1:
		return static_cast<Base *>(new B());
	default:
		return static_cast<Base *>(new C());
	}
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);

	if (a)
		a->print_type();
	if (b)
		b->print_type();
	if (c)
		c->print_type();
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		a.print_type();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		b.print_type();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		c.print_type();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	Base	*base = generate();
	identify(base);
	identify(*base);

	return 0;
}

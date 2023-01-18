/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:00:26 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 18:08:09 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

Literal::Literal(): _s("")
{
}

Literal::Literal(const std::string input): _s(input)
{
}

Literal::Literal(const Literal &copy): _s(copy._s)
{
}

Literal	&Literal::operator=(const Literal &copy)
{
	(void) copy;
	return *this;
}

char	Literal::toChar() const
{
	
}

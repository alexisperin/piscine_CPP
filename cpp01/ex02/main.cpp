/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:34:24 by aperin            #+#    #+#             */
/*   Updated: 2023/01/06 15:52:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << &str << std::endl;
	std::cout << stringPTR<< std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR<< std::endl;
	std::cout << stringREF << std::endl;
}

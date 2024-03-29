/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:26 by aperin            #+#    #+#             */
/*   Updated: 2023/04/03 17:01:26 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data	*data = new Data();
	std::cout << "data: " << *data << std::endl;

	uintptr_t	raw = Serializer::serialize(data);
	std::cout << "raw pointer: " << raw << std::endl;

	Data	*new_data = Serializer::deserialize(raw);
	std::cout << "new data: " << *new_data << std::endl;

	delete data;

	return 0;
}

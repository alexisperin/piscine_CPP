/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:52:26 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 14:12:41 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main()
{
	Data	*data = new Data();
	std::cout << "data: " << *data << std::endl;

	uintptr_t	raw = serialize(data);
	std::cout << "raw pointer: " << raw << std::endl;

	Data	*new_data = deserialize(raw);
	std::cout << "new data: " << *new_data << std::endl;

	delete data;

	return 0;
}

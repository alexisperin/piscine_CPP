/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:59:00 by aperin            #+#    #+#             */
/*   Updated: 2023/04/11 08:55:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T *array, size_t size, void (*f)(T &))
{
	if (!f)
		return ;
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void	print_data(T &data)
{
	std::cout << data << std::endl;
}
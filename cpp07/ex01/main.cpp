/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:03:33 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 17:09:25 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int	int_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string	string_array[] = {"How", "are", "you", "?"};

	iter(int_array, 10, &print_data);
	iter(string_array, 4, &print_data);

	return 0;
}

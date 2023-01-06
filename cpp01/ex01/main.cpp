/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:10:46 by aperin            #+#    #+#             */
/*   Updated: 2023/01/06 15:31:57 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	int	N = 10;
	Zombie	*horde = zombieHorde(N, "Michel");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
}

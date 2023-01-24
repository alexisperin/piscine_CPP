/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:41:03 by aperin            #+#    #+#             */
/*   Updated: 2023/01/24 10:50:32 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class ElementNotFoundException: public std::exception
{
	public:
		const char	*what() const throw()
		{
			return "[ElementNotFoundException]";
		}
};

template<typename T>
void	easyfind(T &container, int i)
{
	typename T::const_iterator	iter;

	iter = std::find(container.begin(), container.end(), i);
	if (iter == container.end())
		throw ElementNotFoundException();
	std::cout << "Element found: " << *iter << std::endl;
};

#endif

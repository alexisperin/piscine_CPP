/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:11:32 by aperin            #+#    #+#             */
/*   Updated: 2023/01/23 17:31:20 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_array;

	public:
		Array()
		{
			this->_size = 0;
			this->_array = new T[0];
		};

		Array(unsigned int n)
		{
			this->_size = n;
			this->_array = new T[n];
		};

		Array(const Array &copy)
		{
			*this = copy;
		};

		~Array()
		{
			delete T[];
		};

		Array	&operator=(const Array &copy)
		{
			this->_size = copy._size;
			delete this->_array[];
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = copy._array[i];

			return *this;
		};

		T	&operator[](unsigned int i)
		{
			if (i < 0 || i >= this->_size)
				throw Array::OutOfRangeExcpetion();
			return this->_array[i];
		};

		class OutOfRangeException: public std::exception
		{
			const char	*what() const throw
			{
				return "[OutOfRangeException]";
			}
		};

		unsigned int	size() const
		{
			return this->_size;
		};
};

#endif

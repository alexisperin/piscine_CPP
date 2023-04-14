/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:44:45 by aperin            #+#    #+#             */
/*   Updated: 2023/04/14 20:59:31 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

RPN::RPN(): _str(""), _error(false)
{
}

RPN::RPN(const RPN &copy): _str(copy._str), _error(copy._error)
{
}

RPN::RPN(const std::string &str): _str(str), _error(false)
{
}

RPN	&RPN::operator=(const RPN &copy)
{
	this->_str = copy._str;
	this->_error = copy._error;
	return *this;
}

RPN::~RPN()
{
}

void	RPN::setSequence(const std::string &str)
{
	this->_str = str;
}

void	RPN::execute()
{
	char	c;
	std::stack<int>	stack;

	for (unsigned int i = 0; i < this->_str.length(); i++)
	{
		c = this->_str[i];
		if (isdigit(c))
			stack.push(c - 48);
		else
		{
			if (stack.size() < 2)
			{
				std::cout << "Error: bad input format\n";
				return ;
			}
			int	n1 = stack.top();
			stack.pop();
			int	n2 = stack.top();
			stack.pop();
			stack.push(_compute(n1, n2, c));
			if (this->_error)
				return ;
		}
		if (this->_str[i + 1] != ' ' && this->_str[i + 1] != 0)
		{
			std::cout << "Error: bad input format\n";
			return ;
		}
		i++;
	}
	if (stack.size() != 1)
		std::cout << "Error: bad input format\n";
	else
		std::cout << stack.top() << std::endl;
}

int RPN::_compute(int n1, int n2, char c)
{
	switch (c)
	{
		case '+':
			return n2 + n1;
		case '-':
			return n2 - n1;
		case '*':
			return n2 * n1;
		case '/':
			if (n1 == 0)
			{
				std::cout << "Error: division by 0\n";
				this->_error = true;
				return 0;
			}
			return n2 / n1;
		default:
			this->_error = true;
			return 0;
	}
}

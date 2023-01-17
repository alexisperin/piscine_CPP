/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:26:40 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 18:31:07 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Form
{
	private:
		std::string	_name;
		bool		_signed;
		const int	_grade_sign;
		const int	_grade_exe;

	public:
		Form();
		Form(const std::string &name, int grade_sign, int grade_exe);
		Form(const Form &copy);
		~Form();
		Form	&operator=(const Form &copy);
};

#endif

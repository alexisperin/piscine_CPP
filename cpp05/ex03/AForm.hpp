/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:26:40 by aperin            #+#    #+#             */
/*   Updated: 2023/01/18 15:53:45 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	_name;
		std::string	_target;
		bool		_signed;
		const int	_grade_sign;
		const int	_grade_exe;

	public:
		AForm();
		AForm(const std::string &name, const std::string &target,
			int grade_sign, int grade_exe);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm	&operator=(const AForm &copy);

		std::string	getName() const;
		std::string	getTarget() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExe() const;
		void				beSigned(Bureaucrat &bureaucrat);

		virtual void		execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &b);

#endif

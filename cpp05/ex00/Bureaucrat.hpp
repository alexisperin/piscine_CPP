/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:45 by aperin            #+#    #+#             */
/*   Updated: 2023/01/17 15:49:47 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif

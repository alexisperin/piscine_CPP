/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:28:39 by aperin            #+#    #+#             */
/*   Updated: 2023/04/03 12:17:10 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", "", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm("ShrubberyCreationForm", copy.getTarget(), 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	(void) copy;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw ShrubberyCreationForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExe())
		throw ShrubberyCreationForm::GradeTooLowException();

	std::ofstream	target;
	target.open(this->getTarget().append("_shrubbery"), std::ios::out);
	if (!target.is_open())
		return ;
	target << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⡀⠀⠀⢀⢀⣀⣤\n"
		<< "⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣾⣿⣿⣿⣿\n"
		<< "⣤⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣡⣴⣦⢄⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⠛⠾⠧⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⢸⠀⠀⠀⢸⣿⣿⣿⠿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⣠⠤⢬⡀⠀⠀⢸⣿⠟⠁⠀⢻⣿⣿⡿⠁⢀⢤⡈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢻⣿⣿⣿⣿⣿⠃⢰⠁⠀⠘⡍⠢⠀⠟⠁⠀⠀⢀⡾⠿⣿⠁⠀⠎⠀⠑⠄⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣿⣿⣿⣿⡇⠀⢸⠀⠀⠀⢳⣶⣄⠀⠀⠀⠀⠋⠀⠀⠈⠀⢸⠃⠋⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠈⣭⣿⣿⣿⣧⠀⠸⠀⠀⠀⠈⢿⠿⠂⣀⡤⠖⠊⠁⠀⠀⠀⠀⠓⠾⠙⡄⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⡇⠈⠻⢿⣿⣆⡀⠳⠀⠀⣠⡴⠒⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⡀⡸⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		<< "⠛⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣅⡀⠀⣦⡀⠀⠁⠀⢀⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡭⠋⠁⣠⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀\n"
		<< "⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡋⡀⠘⢿⡄⠀⠀⠀⠀⡰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠉⠀⢀⠴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣶⡶\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡈⣤⣊⡠⠤⡄⢀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡑⠋⠁⠀⠀⠈⠻⣿⣿⣿⠿⠛⠉⠀⠀\n"
		<< "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠉⠓⠢⣼⠴⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⠈⠻⡀⠀⠀⠀⠀⠀\n"
		<< "⣿⣿⣿⣿⣿⣿⠿⠿⠛⠛⢋⣽⣿⣿⣿⡇⠀⠀⠁⠀⠀⣠⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡞⢸⠀⠀⠀⠀⠀⠀⠀⠀⠙⢶⠢⠤⢤⣀\n"
		<< "⡿⠟⠛⠉⠀⠀⠀⠀⢀⣴⠿⠟⠛⠛⠛⠻⡄⠀⠀⠀⠰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢶⠟⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠣⠀⠀⠈\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠵⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠜⡽⠋⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠢⢤⣀⠀⠀⠀⠀⠀⢀⣴⡡⠊⠀⠀⠀⢠⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣄⠉⠒⠢⠤⢤⡟⠋⠀⠀⠀⠀⢀⡎⠀⡄⠀⠀⠀⠀⢀⡠⠤⠒⠀⠀⡄⠀⠀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠈⠁⠀⠀⠐⠀⢧⠀⠳⣄⠀⠀⡜⠀⡘⠀⠀⣀⠔⠊⠁⠀⠀⠀⢠⠎⠀⠀⠀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢽⣇⠀⠈⠁⡼⠀⡰⣠⠔⠁⠀⠀⠀⠀⠀⢀⡔⠁⠀⠀⠀⠀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢸⠀⠀⠰⢀⡸⠋⠀⠀⠀⠀⠀⠀⢀⣤⠎⠀⠀⠀⠀⠀⠀\n"
		<< "⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⢉⣿⠘⠀⠀⡷⠋⠀⠀⠀⠀⠀⢀⣠⣶⡟⠁⠀⠀⠀⠀⠀⠀⠀\n";
	target.close();
}

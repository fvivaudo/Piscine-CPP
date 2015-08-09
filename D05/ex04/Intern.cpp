/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructed" << std::endl;
	return;
}

Intern::~Intern(void)
{
	std::cout << "Intern destroyed" << std::endl;
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	if (name == "robotomy request")
	{
		std::cout << "Intern creates " << name << "." << std::endl;
		return new RobotomyRequestForm(target);
	}
	else 	if (name == "shrubbery creation request")
	{

		std::cout << "Intern creates " << name << "." << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else 	if (name == "presidential pardon form")
	{
		std::cout << "Intern creates " << name << "." << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << "The form is unknown, Intern can't create it." << name << std::endl;
		return NULL;
	}
	return NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 14:58:25 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/22 14:58:26 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <iostream>

int main(void)
{
//	Bureaucrat a("Fry", 150);
//	Bureaucrat b("Hermes Conrad", 36);
//	Bureaucrat c("Number 1.0", 1);
//	Intern someRandomIntern;
	/*Form d("Hard Contract", 78, 120);
	Form e("Hard Contract", 78, 151);
	Form f("Hard Contract", 152, 1);

	std::cout << b << std::endl;
	std::cout << d << std::endl;
	d.beSigned(a);
	std::cout << d << std::endl;
	a.signForm(d);
	b.signForm(d);
	a.signForm(d);
	std::cout << d << std::endl;
*/

/*
	Form* fa;
	Form* fb;
	Form* fc;
	Form* fd;

	fa = someRandomIntern.makeForm("robotomy request", "Hermes");
	fb = someRandomIntern.makeForm("shrubbery creation request", "42");
	fc = someRandomIntern.makeForm("presidential pardon form", "Nixon");
	fd = someRandomIntern.makeForm("Fire intern", "Slave");
	//ShrubberyCreationForm	fa("42");
//	RobotomyRequestForm		fb("Hermes");
//	PresidentialPardonForm	fc("Nixon");

	std::cout << *fa << std::endl;
	std::cout << *fb << std::endl;
	std::cout << *fc << std::endl;
	b.signForm(*fa);
	b.signForm(*fb);
	std::cout << *fa << std::endl;
	std::cout << *fb << std::endl;
	std::cout << *fc << std::endl;
	b.executeForm(*fc);
	b.executeForm(*fa);
	std::cout << *fa << std::endl;
	std::cout << *fb << std::endl;
	std::cout << *fc << std::endl;
	b.signForm(*fc);
	c.signForm(*fc);
	b.executeForm(*fc);
	b.executeForm(*fb);
	c.executeForm(*fc);
*/

	//Form* rrf;
	//rrf = someRandomIntern.makeForm("robotomy request", "Bender");
Intern* idiotOne= new Intern;
Bureaucrat *hermes = new Bureaucrat("Hermes Conrad", 37);
Bureaucrat *bob = new Bureaucrat("Number 1.0", 1);
OfficeBlock ob;
ob.setIntern(idiotOne);
ob.setSigner(hermes);
ob.setExecutor(bob);
ob.doBureaucracy("presidential pardon form", "Nixon");

	return (0);
}
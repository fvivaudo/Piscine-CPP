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
#include <iostream>

int main(void)
{
	Bureaucrat a("Fry", 150);
	Bureaucrat b("Hermes Conrad", 36);
	Bureaucrat c("Number 1.0", 1);
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

	ShrubberyCreationForm	fa("42");
	RobotomyRequestForm		fb("Hermes");
	PresidentialPardonForm	fc("Nixon");

	std::cout << fa << std::endl;
	std::cout << fb << std::endl;
	std::cout << fc << std::endl;
	b.signForm(fa);
	b.signForm(fb);
	std::cout << fa << std::endl;
	std::cout << fb << std::endl;
	std::cout << fc << std::endl;
	b.executeForm(fc);
	b.executeForm(fa);
	std::cout << fa << std::endl;
	std::cout << fb << std::endl;
	std::cout << fc << std::endl;
	b.signForm(fc);
	c.signForm(fc);
	b.executeForm(fc);
	b.executeForm(fb);
	c.executeForm(fc);
	return (0);
}
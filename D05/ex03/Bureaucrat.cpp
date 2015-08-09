/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Construction aborted : Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Construction aborted : Grade too low");
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	return;
}

Bureaucrat::Bureaucrat(void) : _name("def"), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string n, int g) : _name(n), _grade(g)
{
	try
	{
		if (g > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else if (g < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else
			std::cout << "Bureaucrat constructed" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destroyed" << std::endl;
}


std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::signForm(Form & con)
{
	if (con.beSigned(*this))
	{
		std::cout << this->_name << " signs " << con.getName() << "." << std::endl;
	}
	else if (!con.getSigned())
	{
		std::cout << this->_name << " cannot sign " << con.getName() << " because his level is too low." << std::endl;
	}
	else
	{
		std::cout << this->_name << " cannot sign " << con.getName() << " because the form is already signed." << std::endl;
	}

}

std::ostream &	operator<<(std::ostream & o ,Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}

void		Bureaucrat::executeForm(Form const & form)
{
	if (form.execute(*this))
	{
		std::cout << this->_name << " execute " << form.getName() << "." << std::endl;
	}
	else if (form.getSigned())
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because his level is too low." << std::endl;
	}
	else
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because the form isn't signed." << std::endl;
	}
	
}











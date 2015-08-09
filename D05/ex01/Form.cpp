/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"


const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception : Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception : Grade too low");
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	return;
}

Form::GradeTooHighException::GradeTooHighException()
{
	return;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	return;
}

Form::GradeTooLowException::GradeTooLowException()
{
	return;
}

Form::Form(void) : _name("Default contract"), _grade(150), _signed(0), _min_grade(150)
{
	return;
}

Form::Form(std::string n, int g_exe, int g_sign) : _name(n), _grade(g_exe), _signed(0), _min_grade(g_sign)
{
	try
	{
		if (g_sign > 150 || g_exe > 150)
		{
			throw Form::GradeTooLowException();
		}
		else if (g_sign < 1 || g_exe < 150)
		{
			throw Form::GradeTooHighException();
		}
		else
			std::cout << "Form constructed" << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return;
}
bool	Form::beSigned(Bureaucrat const & bur)
{
	try
	{
		if (bur.getGrade() > this->_min_grade)
		{
			throw Form::GradeTooLowException();
			return (0);
		}
		else
		{
			this->_signed = 1;
			return (1);
		}
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

Form::~Form(void)
{
	std::cout << "Form destroyed" << std::endl;
}


std::string	Form::getName() const
{
	return (this->_name);
}

int			Form::getGrade() const
{
	return (this->_grade);
}

int			Form::getMinGrade() const
{
	return (this->_min_grade);
}

bool		Form::getSigned() const
{
	return (this->_signed);
}

std::ostream &	operator<<(std::ostream & o ,Form const & rhs )
{
	o << "Form " << rhs.getName() << ", grade required to sign it " << rhs.getMinGrade() << ", grade required to execute it " << rhs.getGrade() << ", state of the form = " <<rhs.getSigned() << ".";
	return (o);
}















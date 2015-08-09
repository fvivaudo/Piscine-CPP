/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:45 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/22 16:22:49 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string n, int g);
	~Bureaucrat(void);
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
		~GradeTooHighException() throw();
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const & src);
	private:
		GradeTooHighException &	operator=( GradeTooHighException const & rhs );
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
		~GradeTooLowException() throw();
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const & src);
	private:
		GradeTooLowException &	operator=( GradeTooLowException const & rhs );
	};
	std::string			getName() const;
	int					getGrade() const;
	void				signForm(Form & con);

private:
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat &	operator=( Bureaucrat const & rhs );
	const	std::string	_name;
	int					_grade;

};

std::ostream &	operator<<(std::ostream & o ,Bureaucrat const & rhs );

#endif

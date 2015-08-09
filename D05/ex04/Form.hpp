/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:45 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/22 16:22:49 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(std::string n, int g_exe, int g_sign);
	~Form(void);
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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
		~FormNotSignedException() throw();
		FormNotSignedException();
		FormNotSignedException(FormNotSignedException const & src);
	private:
		FormNotSignedException &	operator=( FormNotSignedException const & rhs );
	};
	bool			execute(Bureaucrat const & executor) const;
	std::string		getName() const;
	int				getGrade() const;
	bool			getSigned() const;
	int				getMinGrade() const;
	bool			beSigned(Bureaucrat const & bur);
	virtual	void	Action(void) const = 0;
private:
	Form(Form const & src);
	Form &	operator=( Form const & rhs );
	const	std::string	_name;
	const	int			_grade;
	bool				_signed;
	int					_min_grade;

};

std::ostream &	operator<<(std::ostream & o ,Form const & rhs );

#endif

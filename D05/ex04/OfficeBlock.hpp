/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:45 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/22 16:22:49 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP
# include <iostream>
# include "Form.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class OfficeBlock
{
public:
	OfficeBlock(void);
	OfficeBlock(Intern	*slave, Bureaucrat	*signer, Bureaucrat *executor);
	~OfficeBlock(void);
	void	doBureaucracy(std::string name, std::string target);
	void	setIntern(Intern *slave);
	void	setSigner(Bureaucrat *signer);
	void	setExecutor(Bureaucrat *executor);
private:
	Intern		*_slave;
	Bureaucrat	*_signer;
	Bureaucrat	*_executor;
	OfficeBlock(OfficeBlock const & src);
	OfficeBlock &	operator=( OfficeBlock const & rhs );
};


#endif

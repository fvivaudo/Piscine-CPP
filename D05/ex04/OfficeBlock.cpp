/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) : _slave(NULL), _signer(NULL), _executor(NULL)
{
	std::cout << "OfficeBlock constructed" << std::endl;
	return;

}
OfficeBlock::OfficeBlock(Intern	*slave, Bureaucrat	*signer, Bureaucrat *executor) : _slave(slave), _signer(signer), _executor(executor)
{
	std::cout << "OfficeBlock constructed" << std::endl;
	return;
}

OfficeBlock::~OfficeBlock(void)
{
	std::cout << "OfficeBlock destroyed" << std::endl;
}

void	OfficeBlock::setIntern(Intern *slave)
{
	this->_slave = slave;
}

void	OfficeBlock::setSigner(Bureaucrat *signer)
{
	this->_signer = signer;
}

void	OfficeBlock::setExecutor(Bureaucrat *executor)
{
	this->_executor = executor;
}

void	OfficeBlock::doBureaucracy(std::string name, std::string target)
{
	Form *rrf;
	if ((rrf = this->_slave->makeForm(name, target)) && this->_signer->signForm(*rrf) && this->_executor->executeForm(*rrf))
	{
		std::cout << "Ahhhh.. Wonderful bureaucracy." << std::endl;
	}
	else
		std::cout << "This won't work." << std::endl;
	return;
}

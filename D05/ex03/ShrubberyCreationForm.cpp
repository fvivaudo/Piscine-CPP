/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form ("ShrubberyCreationForm contract", 137, 145), _target("default")
{
	std::cout << "ShrubberyCreation Form constructed" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string n) : Form ("ShrubberyCreationForm contract", 137, 145), _target(n)
{
	std::cout << "ShrubberyCreationForm constructed" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}


void	ShrubberyCreationForm::Action(void) const
{
	std::ofstream out (this->_target);
	out << "ASCII trees";
}

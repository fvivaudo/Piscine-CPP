/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form ("RobotomyRequestForm contract", 45, 72), _target("Random citizen")
{
	srand(time(NULL));
	std::cout << "RobotomyRequest Form constructed" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string n) : Form ("RobotomyRequestForm contract", 45, 72), _target(n)
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm constructed" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}


void	RobotomyRequestForm::Action(void) const
{
	if (rand() % 2)
		std::cout << "*Drilling noises* " << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "*Drilling noises* " << this->_target << " died during the operation." << std::endl;
}

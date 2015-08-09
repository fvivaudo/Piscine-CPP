/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form ("PresidentialPardonForm contract", 5, 25), _target("Random citizen")
{
	std::cout << "PresidentialPardon Form constructed" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string n) : Form ("PresidentialPardonForm contract", 5, 25), _target(n)
{
	std::cout << "PresidentialPardonForm constructed" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}


void	PresidentialPardonForm::Action(void) const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

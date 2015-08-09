/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:07:10 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 19:07:10 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _w(NULL)
{
	std::cout << "HumanB is born" << std::endl;
}

HumanB::~HumanB( void )
{
	std::cout << "HumanB died" << std::endl;
}
void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_w->getType() << std::endl;
}
void	HumanB::setWeapon(Weapon &w)
{
	this->_w = &w;
}
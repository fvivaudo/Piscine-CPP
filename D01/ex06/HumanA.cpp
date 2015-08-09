/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:07:02 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 19:07:04 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon &w) : _name(name), _w(w)
{
	std::cout << "HumanA is born" << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << "HumanA died" << std::endl;
}
void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_w.getType() << std::endl;
}
void	HumanA::setWeapon(Weapon &w)
{
	this->_w = w;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:06:25 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 19:06:27 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"
#include <string>
#include <iostream>

Weapon::Weapon(std::string name) : _type(name)
{
	std::cout << "Weapon created" << std::endl;
}
Weapon::~Weapon( void )
{
	std::cout << "Weapon destroyed" << std::endl;
}
std::string&	Weapon::getType(void)
{
	return (this->_type);
}
void			Weapon::setType(std::string newtype)
{
	this->_type = newtype;
	//std::cout << this->_type << std::endl;
	return;
}

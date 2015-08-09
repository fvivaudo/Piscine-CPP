/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:29:21 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 11:29:24 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string Name, std::string Type) : name(Name), type(Type)
{
	std::cout << Name << " has emerged from the dead, (s)he's a " << Type << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << name << " wasted away, (s)he was a " << this->type << std::endl;
}

void Zombie::announce( void ) const
{
	std::cout << "<" << this->name << "(" << this->type << ")>" << "Braiiiiiiinnnssss..." << std::endl;
}
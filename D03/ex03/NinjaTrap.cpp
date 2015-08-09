/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	return;
}

NinjaTrap::NinjaTrap(std::string n) : ClapTrap(n, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "NinjaTrap constructed" << std::endl;

	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src):ClapTrap(src)
{
	std::cout << "NinjaTrap copied" << std::endl;
	*this = src;

	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap destroyed" << std::endl;
}

NinjaTrap &		NinjaTrap::operator=( NinjaTrap const & rhs)
{
	std::cout << "Assignement operator called" << std::endl;

	if (this != &rhs)
	{
		this->hp = rhs.hp;
		this->max_hp = rhs.max_hp;
		this->mana = rhs.mana;
		this->max_mana = rhs.max_mana;
		this->level = rhs.level;
		this->name = rhs.name;
		this->melee = rhs.melee;
		this->ranged = rhs.ranged;
		this->armor = rhs.armor;
	}
	return (*this);	
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & target)
{
	std::cout << this->name << " takes out another ninja named " << target.name << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const & target)
{
	std::cout << this->name << " takes out a FragTrap named " << target.name << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
	std::cout << this->name << " takes out a ScavTrap named " << target.name << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	srand(time(NULL));

	return;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n, 100, 100, 100, 100, 1, 30, 20, 5)
{
	srand(time(NULL));
	std::cout << "FragTrap constructed" << std::endl;

	return;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap copied" << std::endl;
	*this = src;

	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destroyed" << std::endl;
}

FragTrap &		FragTrap::operator=( FragTrap const & rhs)
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

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int r = rand() % 5;
	if (this->mana < 25)
	{
		std::cout << "You're out of energy" << std::endl;
		return ;
	}
	else if (r == 0)
		std::cout << "Special attack 1 on " << target << std::endl;
	else if (r == 1)
		std::cout << "Special attack 2 on " << target << std::endl;
	else if (r == 2)
		std::cout << "Special attack 3 on " << target << std::endl;
	else if (r == 3)
		std::cout << "Special attack 4 on " << target << std::endl;
	else if (r == 4)
		std::cout << "Special attack 5 on " << target << std::endl;
	if ((this->mana - 25) > 0)
		this->mana -= 25;
	else
		this->mana = 0;

}


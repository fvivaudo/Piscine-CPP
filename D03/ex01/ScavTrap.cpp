/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	srand(time(NULL));

	return;
}

ScavTrap::ScavTrap(std::string n) : name(n), hp(100), max_hp(100), mana(50), max_mana(50), level(1), melee(20), ranged(15), armor(3)
{
	srand(time(NULL));
	std::cout << "ScavTrap constructed" << std::endl;

	return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copied" << std::endl;
	*this = src;

	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destroyed" << std::endl;
}

ScavTrap &		ScavTrap::operator=( ScavTrap const & rhs)
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

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << this->name << " attacks " << target << " at range, causing " << this->ranged << " points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << this->name << " attacks " << target << " at melee range, causing " << this->melee << " points of damage !" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hp == 0)
	{
		std::cout << this->name << " is already dead, you moron ! " << std::endl;
	}
	else if ((amount - this->armor) >= this->hp)
	{
		this->hp = 0;
		std::cout << this->name << " : \"I can see... the code\" "  << std::endl;
	}
	else
	{
		std::cout << this->name << " : \"Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!\" "  << std::endl;
		this->hp -= (amount - this->armor);
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if ((amount + this->hp) > this->max_hp)
	{
		std::cout << this->name << " recovered "  << this->max_hp - this->hp << " HP." << std::endl;
		this->hp = this->max_hp;
	}
	else
	{
		std::cout << this->name << " recovered "  << amount << " HP." << std::endl;
		this->hp += amount;
	}
	std::cout << this->name << " : \"Good as new, I think. Am I leaking?\" "  << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	int r = rand() % 5;
	if (this->mana < 25)
	{
		std::cout << "You're out of energy" << std::endl;
		return ;
	}
	else if (r == 0)
		std::cout << "Challenge 1 on " << target << std::endl;
	else if (r == 1)
		std::cout << "Challenge 2 on " << target << std::endl;
	else if (r == 2)
		std::cout << "Challenge 3 on " << target << std::endl;
	else if (r == 3)
		std::cout << "Challenge 4 on " << target << std::endl;
	else if (r == 4)
		std::cout << "Challenge 5 on " << target << std::endl;
	if ((this->mana - 25) > 0)
		this->mana -= 25;
	else
		this->mana = 0;

}



























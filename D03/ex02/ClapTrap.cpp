/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void)
{
	srand(time(NULL));

	return;
}

ClapTrap::ClapTrap(std::string name, int hp, int max_hp, int mana, int max_mana, int level, int melee, int ranged, int armor) : name(name), hp(hp), max_hp(max_hp), mana(mana), max_mana(max_mana), level(level), melee(melee), ranged(ranged), armor(armor)
{
	srand(time(NULL));
	std::cout << "ClapTrap constructed" << std::endl;

	return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap copied" << std::endl;
	*this = src;

	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destroyed" << std::endl;
}

ClapTrap &		ClapTrap::operator=( ClapTrap const & rhs)
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

void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->name << " attacks " << target << " at range, causing " << this->ranged << " points of damage !" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->name << " attacks " << target << " at melee range, causing " << this->melee << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:54:09 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 13:54:10 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	FragTrap a("Unit1");
	FragTrap b("Unit2");
	FragTrap c("Unit3");

	a = b;
	a.rangedAttack("Unit2");
	b.takeDamage(30);
	a.meleeAttack("Unit2");
	b.takeDamage(30);
	a.rangedAttack("Unit2");
	b.takeDamage(30);
	a.rangedAttack("Unit2");
	b.takeDamage(30);
	a.rangedAttack("Unit2");
	b.takeDamage(30);
	b.beRepaired(150);
	a.vaulthunter_dot_exe("Unit2");
a.vaulthunter_dot_exe("Unit2");
a.vaulthunter_dot_exe("Unit2");
a.vaulthunter_dot_exe("Unit2");
a.vaulthunter_dot_exe("Unit2");

	ScavTrap as("Unit1");
	ScavTrap bs("Unit2");
	ScavTrap cs("Unit3");

	as = bs;
	as.rangedAttack("Unit2");
	bs.takeDamage(30);
	as.meleeAttack("Unit2");
	bs.takeDamage(30);
	as.rangedAttack("Unit2");
	bs.takeDamage(30);
	as.rangedAttack("Unit2");
	bs.takeDamage(30);
	as.rangedAttack("Unit2");
	bs.takeDamage(30);
	bs.beRepaired(150);
	as.challengeNewcomer("Unit2");
as.challengeNewcomer("Unit2");
as.challengeNewcomer("Unit2");
as.challengeNewcomer("Unit2");
as.challengeNewcomer("Unit2");
	return 0;
}
/*
Default constructor called
Copy constructor called
Assignation operator called // <-- This line may be missing depending of your implementation
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
*/
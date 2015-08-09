/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:30:04 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 11:30:05 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent	apocalypse;

	apocalypse.setZombieType("Fatty");
	Zombie* zom = apocalypse.newZombie("Zero");
	zom->announce();
	apocalypse.randomChump();
	apocalypse.randomChump();
	apocalypse.randomChump();
	apocalypse.randomChump();
	apocalypse.randomChump();
	apocalypse.randomChump();

	delete zom;
	return (0);
}
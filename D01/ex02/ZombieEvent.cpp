/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:29:46 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 11:29:47 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <string>
#include <iostream>

ZombieEvent::ZombieEvent(void) : type(""), name("")
{
	srand (time(NULL));
	std::cout << "THIS IS THE END !" << std::endl;
}

ZombieEvent::~ZombieEvent( void )
{
	std::cout << "The Reckoning has been canceled." << std::endl;
}

void		ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie* zom = new Zombie(name, this->type);
	return (zom);
}

void	ZombieEvent::randomChump(void) const
{
	int r;
	std::string name;

	r = rand() % 10;
	if (r == 0)
		name = "Adol";
	else if (r == 1)
		name = "Eve";
	else if (r == 2)
		name = "Cinderella";
	else if (r == 3)
		name = "Shepard";
	else if (r == 4)
		name = "Romulus";
	else if (r == 5)
		name = "Diana";
	else if (r == 6)
		name = "Anaestasia";
	else if (r == 7)
		name = "Moktar";
	else if (r == 8)
		name = "Tuco";
	else if (r == 9)
		name = "Heisenberg";
	Zombie zom(name, this->type);
	zom.announce();
}
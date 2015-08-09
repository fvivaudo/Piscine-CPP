/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 15:26:55 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 15:26:56 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <string>
#include <iostream>

ZombieHorde::ZombieHorde(int N)
{
	int r;
	std::string name;
	this->zom = new Zombie[N];
	std::cout << N << " zombies have formed a horde." << std::endl;

	srand(time(NULL));
	while (N > 0)
	{
		--N;
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
		this->zom[N].name = name;
		this->zom[N].announce();
	}
}

ZombieHorde::~ZombieHorde( void )
{
	delete [] this->zom;
	std::cout << " A horde disbanded. " << std::endl;
}
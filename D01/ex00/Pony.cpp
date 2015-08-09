/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 10:07:58 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 10:07:59 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Pony.hpp"
#include <iostream>

Pony::Pony(int p1) : whatever_you_think_adequately_describes_a_pony(p1)
{
	std::cout << "Pony synthetized" << std::endl;
}

Pony::~Pony( void )
{
	std::cout << "Pony Annihilated" << std::endl;
}

void	Pony::DoSomeStuff(void)
{
	if (this->whatever_you_think_adequately_describes_a_pony == 1)
		std::cout << "Pony is heaping around" << std::endl;
	else
		std::cout << "Pony is getting stacked" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:46:33 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 16:46:34 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.hpp"
#include <string>
#include <iostream>

Human::Human(void)
{
	std::cout << "Someone is born." << std::endl;
}

Human::~Human( void )
{
	std::cout << "Someone wasted away, alone and desperate, gasping for one final breathe before death became his sole companion in the midst of an empty hopital room." << std::endl;
}

std::string		Human::identify(void) const
{
	return (b.identify());
}

Brain	const&	Human::getBrain(void) const
{
	return (this->b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:46:11 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 16:46:12 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"
#include <string>
#include <iostream>
#include <sstream>

Brain::Brain(void)
{
	std::cout << "A brain has emerged from dust." << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Braindead." << std::endl;
}

std::string	Brain::identify( void ) const
{
	std::stringstream	ss;

	ss << (void *)this;
	return (ss.str());
}
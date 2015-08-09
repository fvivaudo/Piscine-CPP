/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:46:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 16:46:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "human.hpp"
#include "brain.hpp"

int main()
{
	Human			bob;

	std::cout	<<	bob.identify() << std::endl;

	std::cout	<<	bob.getBrain().identify() << std::endl;
	return (0);
}

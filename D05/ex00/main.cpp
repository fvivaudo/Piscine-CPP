/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 14:58:25 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/22 14:58:26 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat a("Fry", 678);
	Bureaucrat z("God", 0);
	Bureaucrat b("Hermes Conrad", 36);
	Bureaucrat d;

	std::cout << b << std::endl;
	std::cout << d << std::endl;
	return (0);
}
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
	Bureaucrat a("Fry", 150);
	Bureaucrat b("Hermes Conrad", 36);
	Form d("Hard Contract", 78, 120);
	Form e("Hard Contract", 78, 151);
	Form f("Hard Contract", 152, 1);

	std::cout << b << std::endl;
	std::cout << d << std::endl;
	d.beSigned(a);
	std::cout << d << std::endl;
	a.signForm(d);
	b.signForm(d);
	a.signForm(d);
	std::cout << d << std::endl;
	return (0);
}
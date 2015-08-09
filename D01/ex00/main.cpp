/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 10:08:12 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 10:08:13 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony* p = new Pony(1);
	p->DoSomeStuff();
	delete p;
}

void	ponyOnTheStack(void)
{
	Pony p(2);
	p.DoSomeStuff();
}

int main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();


	return (0);
}
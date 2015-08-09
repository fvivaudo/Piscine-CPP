/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 18:26:31 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/23 18:26:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>


template <typename A, typename B, typename C>

void iter (A & str, unsigned int len, B (*foo)(C))
{
	unsigned int i = 0;;

	while (i < len)
	{
		foo(str[i]);
		++i;
	}
}

int main ()
{
	std::string s2 = "World\n";
	int t[] = {87, 111, 114, 108, 100, 10};
	iter("World\n", 6, &putchar);
	iter(s2, 6, &putchar);
	iter(t, 6, &putchar);
	return 0;
}
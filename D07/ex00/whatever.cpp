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


template <typename T>
T const& max (T const& a, T const& b) 
{ 
	return a < b ? b : a;
}

template <typename T>
T const& min (T const& a, T const& b) 
{ 
	return a > b ? b : a;
}

template <typename T>
void swap (T & a, T & b) 
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
} 

int main ()
{

	int i = 39;
	int j = 20;
	std::cout << "max(i, j): " << max(i, j) << std::endl;
	std::cout << "min(i, j): " << min(i, j) << std::endl;
	double f1 = 13.5;
	double f2 = 20.7;
	std::cout << "max(f1, f2): " << max(f1, f2) << std::endl;
	std::cout << "min(f1, f2): " << min(f1, f2) << std::endl;
	std::string s1 = "Hello";
	std::string s2 = "World";

	std::cout << "s1, s2: " << s1 << " " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "s1, s2: " << s1 << " " << s2 << std::endl;
	std::cout << "f1, f2: " << f1 << " " << f2 << std::endl;
	swap(f1, f2);
	std::cout << "f1, f2: " << f1 << " " << f2 << std::endl;
	std::cout << "i, j: " << i << " " << j << std::endl;
	swap(i, j);
	std::cout << "i, j: " << i << " " << j << std::endl;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 20:53:57 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/25 20:53:58 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.tpp"
#include <iostream>
#include <string>

int            main(void)
{
	{
		std::cout << "Array avec des int:" << std::endl;
		Array<int>        a;
		Array<int>        b(4);
		unsigned int    i = 0;

		b[0] = 1;
		b[1] = 2;
		b[2] = 3;
		b[3] = 4;
		a = b;
		a[0] = 4;
		a[1] = 3;
		a[2] = 2;
		a[3] = 1;
//		Array<int>        b(a);
		std::cout << b[4] << std::endl;
		while (i < a.size())
		{
			std::cout << "\ta: " << a[i] << "\t\tb: " << b[i] << std::endl;
			i++;
		}
		std::cout << std::endl;
		std::cout << "\tTentative d'accès à b[1234567890]: ";
		try
		{
			b[1234567890] = 12;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Array avec des float:" << std::endl;
		Array<float>        a;
		Array<float>        b(4);
		unsigned int    i = 0;

		b[0] = 1.23f;
		b[1] = 2.24f;
		b[2] = 3.35f;
		b[3] = 4.23f;
		a = b;
		a[0] = 4.23f;
		a[1] = 3.35f;
		a[2] = 2.65f;
		a[3] = 1.58f;
		while (i < a.size())
		{
			std::cout << "\ta: " << a[i] << "\t\tb: " << b[i] << std::endl;
			i++;
		}
		std::cout << std::endl;
		std::cout << "\tTentative d'accès à b[1234567890]: ";
		try
		{
			b[1234567890] = 12.43f;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Array avec des char:" << std::endl;
		Array<char>        a;
		Array<char>        b(4);
		unsigned int    i = 0;

		b[0] = 'b';
		b[1] = 'B';
		b[2] = '&';
		b[3] = '_';
		a = b;
		a[0] = 'a';
		a[1] = 'A';
		a[2] = '@';
		a[3] = '!';
		while (i < a.size())
		{
			std::cout << "\ta: " << a[i] << "\t\tb: " << b[i] << std::endl;
			i++;
		}
		std::cout << std::endl;
		std::cout << "\tTentative d'accès à b[1234567890]: ";
		try
		{
			b[1234567890] = '1';
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Array avec des double:" << std::endl;
		Array<double>        a;
		Array<double>        b(4);
		unsigned int    i = 0;

		b[0] = -12.3;
		b[1] = 22.4;
		b[2] = 2.03;
		b[3] = 53.3;
		a = b;
		a[0] = -34.55;
		a[1] = 0.343;
		a[2] = 54.65;
		a[3] = -1.23;
		while (i < a.size())
		{
			std::cout << "\ta: " << a[i] << "\t\tb: " << b[i] << std::endl;
			i++;
		}
		std::cout << std::endl;
		std::cout << "\tTentative d'accès à b[1234567890]: ";
		try
		{
			b[1234567890] = 23.43;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
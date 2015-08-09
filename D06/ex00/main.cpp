/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 18:26:31 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/24 23:32:54 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>
#include <limits.h>

class Convert
{

public :
	Convert (float const v) : _v(v){}
	float getV(void)	{return this->_v;}
	Convert (void);
	~Convert(void){};

	operator char()	
	{
		if (( static_cast<char>(this->_v)) > 32 && static_cast<char>(this->_v) < 127)
			return static_cast<char>(this->_v);
		else if (static_cast<float>(this->_v) != static_cast<float>(this->_v) || static_cast<float>(this->_v) == INFINITY || static_cast<float>(this->_v) == -INFINITY)
			return (1);
		return (0);
	}
	operator float()
	{
		return static_cast<float>(this->_v);
	}
	operator double()
	{
		return static_cast<double>(this->_v);
	}
	operator int()
	{
		return static_cast<int>(this->_v);
	}
private:
	Convert(Convert const & src);
	Convert &	operator=( Convert const & rhs );
	double _v;
};
class Form;

int		main(int ac, char **av)
{

	if (ac == 2)
	{
		int				i = 0;
		int				type = 0;
		std::string		tmp;

		tmp = av[1];
		if (tmp == "-inff" || tmp == "+inff" || tmp == "nanf")
			type = 2;
		else if (tmp == "-inf" || tmp == "+inf" || tmp == "nan")
			type = 1;
		else
		while (tmp[i])
		{
			if (tmp[i] == '.' && type == 0)
				++type;
			else if (tmp[i] == 'f' && type == 1)
				++type;
			++i;
		}
		Convert *a = NULL;
		if (type == 0)
		{
			a = new Convert(atoi(av[1]));
		}
		else if (type == 2)
		{
			a = new Convert(atof(av[1]));
		}
		else if (type == 1)
		{
			a = new Convert(std::strtod(av[1], NULL));
		}

		float 	b = *a;
		double	c = *a;
		int		d = *a;
		char	e = *a;

		std::cout << std::fixed;
		std::cout.precision(1);
		if (std::strtol(av[1], NULL, 10) <= INT_MAX && std::strtol(av[1], NULL, 10) >= INT_MIN)
		{
			if (e == 0)
			{
				std::cout << "char: Non displayable" << std::endl; 
			}
			else if (e == 1)
			{
				std::cout << "char: impossible" << std::endl; 
			}
			else
				std::cout << "char: '" << e << "'" << std::endl;
		//if (b != b) //check NaN
		//if (b == INFINITY)
		//	std::cout << "ok" << d << std::endl;
			if (c != c || c == INFINITY || c <= -INFINITY || c < INT_MIN || c > INT_MAX)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << d << std::endl;

			std::cout << "float: " << b << "f" << std::endl;
		//if (d == INFINITY || d == -INFINITY || d != d)
			std::cout << "double: " << c << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
	return (0);
}

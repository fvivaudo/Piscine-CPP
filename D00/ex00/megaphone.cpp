/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 11:15:30 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/15 11:15:32 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{

	int			i;
	std::string	buff;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			buff += av[i];
			++i;
		}
	}
	i = 0;
	if (buff == "")
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (buff[i])
		{
			buff[i] = toupper(buff[i]);
			++i;
		}
		std::cout << buff << std::endl;
	}
	return (0);
}
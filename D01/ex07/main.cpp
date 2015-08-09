/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 16:20:13 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 16:20:14 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// reading a text file
#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string name = av[1];
		std::ifstream filename;
		std::ofstream out (name + ".replace");
		std::string line;
		size_t len = strlen(av[2]);
		size_t pos;

		filename.open(av[1]);

		if (!filename)
		{
			std::cout << "Could not open " << av[1] << std::endl;
			return (1);
		}
		while (getline(filename, line))
		{
			pos = 0;
			while ((pos = line.find(av[2], pos)) != std::string::npos)
			{
				line.replace(pos, len, av[3]);
				pos += len;
			}
			out << line << std::endl;
		}
		filename.close();
	}
	else
		std::cout << "Wrong number of arguments !" << std::endl;
	return (0);
}
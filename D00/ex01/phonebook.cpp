/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 12:53:41 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/15 12:53:42 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phonebook.hpp>
#include <iostream>
#include <iomanip>

Phone::Phone(void) : _first(""), _last(""), _nickname(""), _login(""), _postal(""), _email(""), _phone(""), _birthday(""), _favorite(""), _underwear(""), _secret(""){}

Phone::~Phone(void){}

void	contact_print(Phone contact)
{
	std::cout << std::setw(27) << std::right << "First Name : " << std::setw(25) << std::right << contact._first << std::endl;
	std::cout << std::setw(27) << std::right << "Last Name : " << std::setw(25) << std::right << contact._last << std::endl;
	std::cout << std::setw(27) << std::right << "Nickname : " << std::setw(25) << std::right << contact._nickname << std::endl;
	std::cout << std::setw(27) << std::right << "Login : " << std::setw(25) << std::right << contact._login << std::endl;
	std::cout << std::setw(27) << std::right << "Code Postal : " << std::setw(25) << std::right << contact._postal << std::endl;
	std::cout << std::setw(27) << std::right << "Email : " << std::setw(25) << std::right << contact._email << std::endl;
	std::cout << std::setw(27) << std::right << "Phone Number : " << std::setw(25) << std::right << contact._phone << std::endl;
	std::cout << std::setw(27) << std::right << "Birthday Date : " << std::setw(25) << std::right << contact._birthday << std::endl;
	std::cout << std::setw(27) << std::right << "Favorite meal : " << std::setw(25) << std::right << contact._favorite << std::endl;
	std::cout << std::setw(27) << std::right << "Color of your underwear : " << std::setw(25) << std::right << contact._underwear << std::endl;
	std::cout << std::setw(27) << std::right << "Your darkest secret : " << std::setw(25) << std::right << contact._secret << std::endl;
}

int main( void )
{

	int			i;
	int			y;
	std::string	buff;
	Phone		num[8];

		i = 0;
	while (1)
	{
		std::cout << ">";
		if (!std::getline(std::cin, buff, '\n'))
			break;
		if (buff == "ADD")
		{
			if (i < 8)
			{
				std::cout << "First Name : " << std::endl;
				std::getline(std::cin, num[i]._first, '\n');
				std::cout << "Last Name : " << std::endl;
				std::getline(std::cin, num[i]._last, '\n');
				std::cout << "Nickname : " << std::endl;
				std::getline(std::cin, num[i]._nickname, '\n');
				std::cout << "Login : " << std::endl;
				std::getline(std::cin, num[i]._login, '\n');
				std::cout << "Code Postal : " << std::endl;
				std::getline(std::cin, num[i]._postal, '\n');
				std::cout << "Email : " << std::endl;
				std::getline(std::cin, num[i]._email, '\n');
				std::cout << "Phone Number : " << std::endl;
				std::getline(std::cin, num[i]._phone, '\n');
				std::cout << "Birthday Date : " << std::endl;
				std::getline(std::cin, num[i]._birthday, '\n');
				std::cout << "Favorite meal : " << std::endl;
				std::getline(std::cin, num[i]._favorite, '\n');
				std::cout << "Color of your underwear : " << std::endl;
				std::getline(std::cin, num[i]._underwear, '\n');
				std::cout << "Your darkest secret : " << std::endl;
				std::getline(std::cin, num[i]._secret, '\n');
				++i;
			}
			else
				std::cout << "The phonebook is full." << std::endl;
		}
		else if (buff == "EXIT")
		{
			exit(0);
		}
		else if (buff == "SEARCH")
		{
			y = 0;
			std::cout << std::setw(10) << std::right << "Index" << "|";
			std::cout << std::setw(10) << std::right << "First Name" << "|";
			std::cout << std::setw(10) << std::right << "Last Name" << "|";
			std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
			while (y < i)
			{
				std::cout << std::setw(10) << std::right << y << "|";
				if (num[y]._first.length() > 10)
					std::cout << std::setw(10) << std::right << num[y]._first.substr(0, 9) + "." << "|";
				else
					std::cout << std::setw(10) << std::right << num[y]._first << "|";
				if (num[y]._last.length() > 10)
					std::cout << std::setw(10) << std::right << num[y]._last.substr(0, 9) + "." << "|";
				else
					std::cout << std::setw(10) << std::right << num[y]._last << "|";
				if (num[y]._nickname.length() > 10)
					std::cout << std::setw(10) << std::right << num[y]._nickname.substr(0, 9) + "." << std::endl;
				else
					std::cout << std::setw(10) << std::right << num[y]._nickname << std::endl;
				++y;
			}
			std::cout << "Index?" << std::endl;
			if (!std::getline(std::cin, buff, '\n'))
				break;
			if (isdigit(buff.c_str()[0]) && atoi(buff.c_str()) < i)
			{
				contact_print(num[atoi(buff.c_str())]);
			}

		}
		else
		{
			std::cout << "Invalid entry." << std::endl;
		}
	}
	return (0);
}


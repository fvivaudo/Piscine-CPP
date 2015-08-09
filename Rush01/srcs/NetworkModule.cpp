/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 22:33:30 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 22:44:16 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule()
{
	this->_totalIO = new long double [4];
	return ;
}

void				NetworkModule::displayTerm()
{
	this->update();
	mvprintw(18, 5, "Network Informations");
	mvprintw(19, 7, "Download: %.1Lf KB/sec\n", this->_totalIO[0]);
	mvprintw(20, 7, "Upload: %.1Lf KB/sec\n", this->_totalIO[1]);
	mvprintw(21, 7, "Packets recieved: %Lg Packets/sec\n", this->_totalIO[2]);
	mvprintw(22, 7, "Packets sent: %Lg Packets/sec\n", this->_totalIO[3]);
	return ;
}

void				NetworkModule::displayGraph(sf::RenderWindow & window)
{
	this->update();
	std::string		buf;
	sf::Text	text;
	sf::Text	title;
	sf::Font	font;

	font.loadFromFile("arial.ttf");
	sf::RectangleShape	rectangle(sf::Vector2f(600, 20));
	rectangle.setPosition(0, 360);
	window.draw(rectangle);

	title.setString("Network Informations");
	title.setFont(font);
	title.setCharacterSize(15);
	title.setColor(sf::Color::Black);
	title.setPosition(25, 362);
	window.draw(title);

	buf = "Download: " + std::to_string(this->_totalIO[0]) + " KB/sec";
	text.setString(buf);
	text.setFont(font);
	text.setCharacterSize(12);
	text.setColor(sf::Color::White);
	text.setPosition(25, 395);
	window.draw(text);

	buf = "Upload: " + std::to_string(this->_totalIO[1]) + " KB/sec";
	text.setString(buf);
	text.setFont(font);
	text.setCharacterSize(12);
	text.setColor(sf::Color::White);
	text.setPosition(25, 415);
	window.draw(text);
	
	buf = "Packets recieved: " + std::to_string(this->_totalIO[2]) + " Packets/sec";
	text.setString(buf);
	text.setFont(font);
	text.setCharacterSize(12);
	text.setColor(sf::Color::White);
	text.setPosition(25, 435);
	window.draw(text);
	
	buf = "Packets send: " + std::to_string(this->_totalIO[3]) + " Packets/sec";
	text.setString(buf);
	text.setFont(font);
	text.setCharacterSize(12);
	text.setColor(sf::Color::White);
	text.setPosition(25, 455);
	window.draw(text);
	return ;
}

void			NetworkModule::update()
{
		caddr_t buf;
		caddr_t end;
		size_t bufsiz;
		struct if_msghdr *ifm;
		long double totalibytes = 0;
		long double totalobytes = 0;
		long double totalipckts = 0;
		long double totalopckts = 0;
		long double difftotalibytes = 0;
		long double difftotalobytes = 0;
		long double difftotalipckts = 0;
		long double difftotalopckts = 0;

		int mib[6] =
		{
			CTL_NET,
			PF_ROUTE,
			0,
			0,
			NET_RT_IFLIST,
			0
		};

		if (sysctl (mib, 6, NULL, &bufsiz, NULL, 0) < 0)
			exit(-1);
			//std::cout << "ECHEC" << std::endl;

	//	buf = (caddr_t)malloc(10000);

		buf = ( caddr_t) ::operator new( 10000 );
		//bufsiz  = sizeof(buf);
		if (sysctl (mib, 6, buf, &bufsiz, NULL, 0) < 0)
		{
			exit(-1); //std::cout << "ECHEC" << std::endl;
		}

		for (end = buf + bufsiz; buf < end; buf += ifm->ifm_msglen) 
		{
			ifm = (struct if_msghdr *) buf;
			if (ifm->ifm_type == RTM_IFINFO)
			{
				totalibytes += ifm->ifm_data.ifi_ibytes;
				totalobytes += ifm->ifm_data.ifi_obytes;
				totalipckts += ifm->ifm_data.ifi_ipackets;
				totalopckts += ifm->ifm_data.ifi_opackets;
			}
		}
		sleep(1);
		if (sysctl (mib, 6, buf, &bufsiz, NULL, 0) < 0)
			exit(-1);//std::cout << "ECHEC" << std::endl;
		for (end = buf + bufsiz; buf < end; buf += ifm->ifm_msglen) 
		{
			ifm = (struct if_msghdr *) buf;
			if (ifm->ifm_type == RTM_IFINFO)
			{
				difftotalibytes += ifm->ifm_data.ifi_ibytes;
				difftotalobytes += ifm->ifm_data.ifi_obytes;
				difftotalipckts += ifm->ifm_data.ifi_ipackets;
				difftotalopckts += ifm->ifm_data.ifi_opackets;
			}
		}
		this->_totalIO[0] = (difftotalibytes - totalibytes) / 1024;
		this->_totalIO[1] = (difftotalobytes - totalobytes) / 1024;
		this->_totalIO[2] = difftotalipckts - totalipckts;
		this->_totalIO[3] = difftotalopckts - totalopckts;

	//	mvprintw(20, 5, "%Lf", (difftotalibytes - totalibytes) / 1024);
}


NetworkModule::~NetworkModule()
{

	return ;
}

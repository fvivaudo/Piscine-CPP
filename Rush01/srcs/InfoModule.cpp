/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:45:02 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 22:37:42 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InfoModule.hpp"

InfoModule::InfoModule()
{
	_gUsername = getUsername();
	_gHostname = getHostname();
	_gSysname = getSysname();
	_gRelease = getRelease();
	_gMachine = getMachine();
	_gOsname = getOsname();
	_gDate = getDate();
	return ;
}

void				InfoModule::printInfo()
{
	mvprintw(1, 5, "General Informations:");
	mvprintw(2, 7, this->_gUsername.c_str());
	mvprintw(2, 14, "@");
	mvprintw(2, 15, this->_gHostname.c_str());
	mvprintw(3, 16, this->_gSysname.c_str());
	mvprintw(3, 23, this->_gRelease.c_str());
	mvprintw(3, 7, this->_gOsname.c_str());
	mvprintw(4, 7, this->_gDate.c_str());
	return ;
}

void				InfoModule::InfoGraph(sf::RenderWindow &  window)
{
	sf::Text				name;
	sf::Text				os;
	sf::Text				date;
	sf::Text				title;
	sf::Font font;

	sf::RectangleShape rectangle(sf::Vector2f(600, 20));

	font.loadFromFile("Arial.ttf");
	std::string buf;

	this->update();

	title.setString("General Informations");
	title.setFont(font);
	title.setCharacterSize(15);
	title.setColor(sf::Color::Black);
	title.setPosition(25, 2);

	buf = this->_gUsername + "@" + this->_gHostname;
	name.setString(buf);
	name.setFont(font);
	name.setCharacterSize(12);
	name.setColor(sf::Color::White);
	name.setPosition(25, 35);

	std::string buf2;
	buf2 = this->_gOsname + " - " + this->_gSysname + this->_gRelease;
	os.setString(buf2);
	os.setFont(font);
	os.setCharacterSize(12);
	os.setColor(sf::Color::White);
	os.setPosition(25, 55);

	date.setString(this->_gDate);
	date.setFont(font);
	date.setCharacterSize(12);
	date.setColor(sf::Color::White);
	date.setPosition(25, 75);

	window.draw(rectangle);
	window.draw(title);
	window.draw(name);
	window.draw(os);
	window.draw(date);

	return ;
}

void				InfoModule::displayTerm()
{
	_gDate = getDate();
	mvprintw(4, 7, _gDate.c_str());
	return ;
}

void				InfoModule::update()
{
	_gDate = getDate();
	return ;
}

std::string				InfoModule::getUsername()
{
	register struct passwd* pw;
	register uid_t			uid;

	uid = geteuid();
	pw = getpwuid(uid);
	if (pw)
		return pw->pw_name;
	else
		return "";
}

std::string				InfoModule::getHostname()
{
	struct utsname	uts;

	uname(&uts);
	return uts.nodename;
}

std::string				InfoModule::getSysname()
{
	struct utsname	uts;

	uname(&uts);
	return uts.sysname;
}

std::string				InfoModule::getRelease()
{
	struct utsname	uts;

	uname(&uts);
	return uts.release;
}

std::string				InfoModule::getMachine()
{
	struct utsname	uts;

	uname(&uts);
	return uts.machine;
}

std::string				InfoModule::getOsname()
{
	#ifdef _WIN32
	return "Windows 32-bit";
	#elif _WIN64
	return "Windows 64-bit";
	#elif __unix || __unix__
	return "Unix";
	#elif __APPLE__ || __MACH__
	return "Mac OS X";
	#elif __linux__
	return "Linux";
	#elif __FreeBSD__
	return "FreeBSD";
	#else
	return "Other";
	#endif
}

std::string				InfoModule::getDate()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d.%m.%Y - %X", &tstruct);
	return buf;
}

InfoModule::~InfoModule()
{
	return ;
}

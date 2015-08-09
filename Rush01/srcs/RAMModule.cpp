/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 22:24:37 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 22:44:47 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RAMModule.hpp>

RAMModule::RAMModule()
{
	this->_mem = getMem();
	return;
}

void				RAMModule::displayTerm()
{
	long double	*mem = getMem();
	mvprintw(14, 5, "Memory Informations (RAM)");
	mvprintw(15, 7, "Available RAM = %.2LfM\n", mem[0] / 1000000);
	mvprintw(16, 7, "Used RAM = %.2LfM\n", mem[1] / 1000000);
	return ;
}

void				RAMModule::update( void )
{
	return ;
}

void				RAMModule::update(sf::RenderWindow & window)
{
	long double	*mem = getMem();
	mem[0] = mem[0] / 1000000;
	mem[1] = mem[1] / 1000000;

	sf::Text	free;
	sf::Text	used;
	sf::Text	title;
	sf::Font	font;
	sf::RectangleShape rectangle(sf::Vector2f(600, 20));
	rectangle.setPosition(0, 280);

	font.loadFromFile("Arial.ttf");
	std::string buf;

	title.setString("Memory Informations (RAM)");
	title.setFont(font);
	title.setCharacterSize(15);
	title.setColor(sf::Color::Black);
	title.setPosition(25, 282);

	buf = "Free memory: " + std::to_string(mem[0]);
	free.setString(buf);
	free.setFont(font);
	free.setCharacterSize(12);
	free.setColor(sf::Color::White);
	free.setPosition(25, 315);

	buf = "Used memory: " + std::to_string(mem[1]);
	used.setString(buf);
	used.setFont(font);
	used.setCharacterSize(12);
	used.setColor(sf::Color::White);
	used.setPosition(25, 335);

	window.draw(rectangle);
	window.draw(title);
	window.draw(free);
	window.draw(used);
	return ;
}

long double	*RAMModule::getMem()
{
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;
	long double	*mem;
	mem = new long double [2];

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
			KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
				(host_info64_t)&vm_stats, &count))
	{
		mem[0] = (int64_t)vm_stats.free_count * (int64_t)page_size;		//free mem
		mem[1] = ((int64_t)vm_stats.active_count +						//mem used?
				(int64_t)vm_stats.inactive_count +
				(int64_t)vm_stats.wire_count) *  (int64_t)page_size;
	}
	return mem;
}

RAMModule::~RAMModule()
{
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksicart <ksicart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:33:04 by ksicart           #+#    #+#             */
/*   Updated: 2015/06/28 22:33:23 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include "CPUModule.hpp"
#include "InfoModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"

void	initTerm( void )
{
	initscr();
	refresh();
	curs_set(0);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	refresh();

	return ;
}

void		usage( char *str )
{
	std::cout << "Usage: " << str << "-[sg]" << std::endl;
	std::cout << "The -s option starts the shell interface" << std::endl;
	std::cout << "The -g option starts the graphic interface" <<std::endl;
	exit(-1);
}

void		useGraphics()
{

	unsigned long		next_game_tick = time(0) * 1000;
	unsigned long		current_game_tick;
	unsigned long		fps = 50;
	unsigned long		skip_ticks = 1000 / fps;
	int					sleep_time = 0;
	CPUModule	cpu;
	InfoModule	im;
	RAMModule	ram;
	NetworkModule	nm;

	sf::RenderWindow window(sf::VideoMode(300, 500), "ft_gkrellm");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
		}
		window.clear();
		im.InfoGraph(window);
		cpu.update(window);
		ram.update(window);
		nm.displayGraph(window);
		window.display();
		current_game_tick = next_game_tick;
		next_game_tick += skip_ticks;
		sleep_time = next_game_tick - current_game_tick;
		if (sleep_time >= 0)
			usleep(sleep_time * 1000);
    }

    return ;
}

void		useTerm()
{

	unsigned long		next_game_tick = time(0) * 1000;
	unsigned long		current_game_tick;
	unsigned long		fps = 30;
	unsigned long		skip_ticks = 1000 / fps;
	int					sleep_time = 0;
	int			ok = 1;
	int			key = 0;
	CPUModule	cpu;
	InfoModule	im;
	RAMModule	ram;
	NetworkModule	nm;

	initTerm();
	im.printInfo();

	while(ok)
	{
		key = getch();
		if (key == 27)
		{
			ok = 0;
		}
		im.displayTerm();
		cpu.displayTerm();
		ram.displayTerm();
		nm.displayTerm();
		refresh();
		current_game_tick = next_game_tick;
		next_game_tick += skip_ticks;
		sleep_time = next_game_tick - current_game_tick;
		if (sleep_time >= 0)
			usleep(sleep_time * 1000);
	}

	erase();
	endwin();
	return ;
}

int			main(int argc, char **argv)
{
	
	srand(time(0));

	if (argc != 2 || argv[1][0] != '-' || (argv[1][1] != 'g' && argv[1][1] != 's'))
		usage( argv[0] );
	if (argv[1][1] == 's')
		useTerm();
	else if (argv[1][1] == 'g')
		useGraphics();
	else
		usage(argv[0]);

	return (0);
}

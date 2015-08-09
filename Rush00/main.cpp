/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 09:37:31 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 13:12:06 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <iostream>
#include "Ship.hpp"
#include "Shoot.hpp"
#include "Background.hpp"
#include "Enemy.hpp"
#include "Foreground.hpp"
#include <unistd.h>
#include <ctime>
#include "Boss.hpp"
#include "Bonus.hpp"


void	InitColors(void)
{
	init_pair(1, 215, -1); //foreground
	init_pair(6, 166, -1); //background
	init_pair(3, 196, -1); //enemy ships
	init_pair(4, 14, -1); //your ship
	init_pair(5, 14, -1); //your bullets
	init_pair(7, 226, -1); //Bonus color
}

void	deleteAll(Ship* ship, Enemy** tab, Background* bg, Foreground* fg, Boss* boss)
{
	int	i;

	i = 0;
	if (ship)
		delete ship;
	if (boss)
		delete boss;
	while (i < 30)
	{
		if (tab[i])
			delete tab[i];
		i++;
	}
	delete fg;
	delete bg;
}

int main(void)
{
	int	 	FiringMod;
	int		i;
	int		x;
	int		y;
	int		v;
	int		z;
	int		ch;
	int		key;
	int		f_count1;
	int		f_count2;
	clock_t	t;
	clock_t f_start;
	clock_t f_end;

	Enemy*	tabEnemy[30];
	std::string	tab[3] = {"/\\", "o=>", "\\/"};

	key = -1;
	f_count1 = 0;
	f_count2 = -1;
	f_start = clock();
	t = clock();
	x = 10;
	y = 10;
	i = 0;
	z = 0;
	initscr();
	curs_set(0);
	start_color();
	use_default_colors();
	WINDOW * win = newwin(60, 250, 0, 0);
	//init_color(6, 760, 462, 380); //background color
	InitColors();
	Bonus	*bonus = new Bonus(340, 12, win, 1, "ice", "0");
	Ship	*ship = new Ship(x, y, win, tab, "-");
	Boss	*boss;
	Background	*bg = new Background(35, 50, 250, win);
	Foreground	*fg = new Foreground(40, 50, 250, win);
	raw();
	nodelay(win, TRUE);
	keypad(win, TRUE);
			while (i < 30)
			{
				tabEnemy[i] = new Enemy(i + 25 + 200, i + 4 + 8, win, 1);
				i++;
			}
	while (true)
	{
		f_end = clock();
		if (f_end - f_start > 25000)
		{
			f_start = f_end;
			++f_count2;
				//	shoot_start = shoot_end;
			ch = wgetch(win);

			if (key != ch && ch != -1 && ch != 32)
			{
				key = ch;
				z = 10;
			}
			else if (ch == -1 && z > 0)
			{
				//usleep(10000);
				if (f_count1 == 0)
				{
					ch = key;
					f_count1 = 0;
					--z;
				}
				else
				{
					ch = -1;
					++f_count1;
				}
			}
			else
				key = -1;
			switch (ch)
			{
				case KEY_UP:
				{
					if (y > 1) y--;
					break;
				}
				case KEY_DOWN:
				{
					if (y < 47) y++;
					break;
				}
				case KEY_RIGHT:
				{
					if (x < 243) x++;
					break;
				}
				case KEY_LEFT:
				{
					if (x > 1) x--;
					break;
				}
				case 32:
				{
				//	ship->createBullet();
					break;
				}
				case 27:
				{
					wclear(win);
					clear();
					endwin();
					deleteAll(ship, tabEnemy, bg, fg, boss);
					return (0);
				}
			}
			if (f_count2 == 4)
			{
				ship->createBullet(1, 0);
				FiringMod = ship->getFiringMod();
				if (FiringMod >= 1)
					ship->createBullet(1, 1);
				if (FiringMod >= 2)
					ship->createBullet(1, -1);
				if (FiringMod >= 3)
					ship->createBullet(5, 1);
				if (FiringMod >= 4)
					ship->createBullet(5, -1);
				if (FiringMod >= 5)
					ship->createBullet(10, 1);
				if (FiringMod >= 6)
					ship->createBullet(10, -1);
				if (FiringMod >= 7)
					ship->createBullet(7, 1);
				if (FiringMod >= 8)
					ship->createBullet(7, -1);
				if (FiringMod >= 9)
					ship->createBullet(2, 1);
				if (FiringMod >= 10)
					ship->createBullet(2, -1);
				if (FiringMod >= 11)
					ship->createBullet(15, 1);
				if (FiringMod >= 12)
					ship->createBullet(15, -1);
				if (FiringMod >= 13)
					ship->createBullet(20, 1);
				if (FiringMod >= 14)
					ship->createBullet(20, -1);
				if (FiringMod >= 15)
					ship->createBullet(0, 1);
				if (FiringMod >= 16)
					ship->createBullet(0, -1);
				f_count2 = 0;

			}
			wclear(win);
			bg->shiftBackground();
			if (ship->getScore() > 1000 && !boss)
				boss = new Boss(180, 15, win, 1);
			i = 0;
			//gen first enemy wave
			while (i < 30)
			{
			//	if (tabEnemy[i] && (tabEnemy[i]->getX() < 0 || tabEnemy[i]->getX() > 200)/* && ship->getScore() > 1000*/)
			//	{
				//	tabEnemy[i]->setX(250);
				//delete tabEnemy[i];
				//	tabEnemy[i] = NULL;
			//	}
				/*else*/
				if (1)
				{
					v = 0;
					Enemy::nb_dead = 0;
					while(v < 30)
					{
						if (tabEnemy[v]->getDead())
						{
							Enemy::nb_dead++;
						}
						++v;
					}
				//	Enemy::nb_dead = 0;
				//	v = 0;
				}
				if (Enemy::nb_dead == 30)
				{
					v = 0;
					while(v < 30)
					{
					//	if (tabEnemy[v]->getDead())
					//	{
							tabEnemy[v]->spawn();
					//	}
						++v;
					}
					break;
				//	Enemy::nb_dead = 0;
				//	v = 0;
				}
				if (tabEnemy[i])
				{
					tabEnemy[i]->move(ship);
				}
				i++;
			}
			//BONUS
			bonus->move(ship);
			if (boss && boss->getDelay() < 0)
			{
			//	boss->_x = 80;
			//	delete boss;
			//	boss = NULL;
			//	break ;
			}
			else if (boss)
				boss->move(ship);
			fg->shiftForeground();
			if (ship->getBullets())
			{
				ship->moveBullets();
			}
			if (ship->moveShip(y, x) == false)
			{
				if (ship->getHP() == 0)
				{
					//delete ship;
					//ship = NULL;
					break;
				}
				else
				{
					y = 10;
					x = 10;
					ship->moveShip(y, x);
				}
			}
			box(win, '|', '-');
			mvwprintw(win, 50, 1, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			mvwprintw(win, 53, 10, "SCORE : %010d", ship->getScore());
			mvwprintw(win, 53, 50, "LIVES : %d", ship->getHP());
			mvwprintw(win, 55, 10, "TIME : %03d", 10 * ((int)(clock() - t)) / CLOCKS_PER_SEC);
		//	mvwprintw(win, 57, 10, "nb_dead : %d", Enemy::nb_dead);
		}
	}
	WINDOW *	win2 = newwin(7, 30, 25, 100);
	box(win2, '|', '-');
	mvwprintw(win2, 2, 10, "Game Over");
	mvwprintw(win2, 3, 6, "Score : %010d", ship->getScore());
		mvwprintw(win2, 4, 7, "Press ESC to exit");
		nodelay(win, false);
		noecho();
		wrefresh(win2);
		keypad(win2, true);
		while ((ch = wgetch(win2)) != 27);
		endwin();
		deleteAll(ship, tabEnemy, bg, fg, boss);
		return(0);
	}

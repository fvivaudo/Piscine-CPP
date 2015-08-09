/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:29:39 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 13:13:48 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cmath>
#include <ncurses.h>
#include "Ship.hpp"
#include "Shoot.hpp"
#include <unistd.h>

Ship::Ship(int x, int y, WINDOW * win, std::string *tab, std::string bullet)
	:_x(x), _y(y), _win(win), _bullet(bullet), _hp(3), _firing_mod(0)
{
	unsigned int	i;

	i = 0;
	while (i <= tab->length())
	{
		this->_coreShip[i] = tab[i];
		i++;
	}
	this->_index = i;
	return;
}

Ship::Ship(void)
	:_x(0), _y(0), _bullet("-"), _hp(3)
{
	_coreShip[0] = ">=>";
	return;
}

Ship::Ship(Ship const & cp)
{
	this->_x = cp.getX();
	this->_y = cp.getY();
	this->_win = cp.getWin();
	return;
}

Ship::~Ship(void)
{
	return;
}

Ship const & Ship::operator=(Ship const & cp)
{
	this->_x = cp.getX();
	this->_y = cp.getY();
	this->_win = cp.getWin();
	return(*this);
}

void	Ship::setWin(WINDOW *win)
{
	this->_win = win;
}

WINDOW	*Ship::getWin(void) const
{
	return(this->_win);
}

void	Ship::setFiringMod(int f)
{
	this->_firing_mod = f;
}

int	Ship::getFiringMod(void) const
{
	return(this->_firing_mod);
}

int	Ship::getX(void) const
{
	return(this->_x);
}

int	Ship::getY(void) const
{
	return(this->_y);
}

void	Ship::setX(int x)
{
	this->_x = x;
}

void	Ship::setY(int y)
{
	this->_y = y;
}

int		Ship::getIndex(void) const
{
	return(this->_index);
}

bool	Ship::moveShip(int y, int x)
{
	unsigned int	tmp;

	wattron(this->_win, COLOR_PAIR(4));
	tmp = mvwinch(this->_win, y + std::floor(this->_index / 2), x) & A_CHARTEXT;
//	if (tmp != '\'' && tmp != ' ' && tmp != '-' && tmp != '(' \
	//		&& tmp != ')' && tmp != 'o')
	if (tmp != ' ' && tmp != '\'' && tmp != '0' && tmp != '-')
	{
		this->_firing_mod = 0;
		this->_hp -= 1;
		return(false);
	}
	for (int i = 0; i < this->_index; i++)
	{
		wmove(this->_win, y + i, x);
		waddstr(this->_win, this->_coreShip[i].c_str());
		wmove(this->_win, y, x);
		this->setX(x);
		this->setY(y);
	}
	wattroff(this->_win, COLOR_PAIR(4));
	return(true);
}

void	Ship::setBonus(std::string str)
{
	int	i;

	i = 0;
	while (!this->_tabBonus[i].empty())
		i++;
	if (i < 3)
		this->_tabBonus[0] = str;
	else
		this->_tabBonus[i] = str;
}

std::string		Ship::getBonus(int index) const
{
	if (!this->_tabBonus[index].empty())
		return (this->_tabBonus[index]);
	return (NULL);
}

void	Ship::createBullet(int d_x, int d_y)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (this->_bullets[i] == NULL)
			break;
		i++;
	}
	if (i < 1000)
	{
		this->_bullets[i] = new Shoot(this->_x, this->_y + std::floor(this->_index / 2), d_x, d_y);
	}
}

bool	Ship::getBullets(void) const
{
	for(int i = 0; i < 1000; i++)
	{
		if (this->_bullets[i] != NULL)
			return(true);
	}
	return(false);
}

Shoot	*Ship::getBulletsBis(int index) const
{
	return (this->_bullets[index]);
}

void	Ship::setBulletNull(int index)
{
	this->_bullets[index] = NULL;
}


void	Ship::moveBullets(void)
{
	int tmp;
	wattron(this->_win, COLOR_PAIR(5));
	for(int i= 0; i < 1000; i++)
	{
		if (this->_bullets[i] != NULL)
		{
			this->_bullets[i]->setX(this->_bullets[i]->getX() + this->_bullets[i]->getd_X());
			this->_bullets[i]->setY(this->_bullets[i]->getY() + this->_bullets[i]->getd_Y());


		//	wmove(this->_win, this->_bullets[i]->getY(), this->_bullets[i]->getX());
		//	waddstr(this->_win, (char *)this->_bullet.c_str());

			tmp = mvwinch(this->_win, this->_bullets[i]->getY(), this->_bullets[i]->getX()) & A_CHARTEXT;
			if (this->_bullets[i]->getY() >= 47 || this->_bullets[i]->getY() <= 0 /*|| (tmp != ' ' && tmp != '\'' && tmp != '-')*/ || tmp == '^')
			{
				delete this->_bullets[i];
				this->_bullets[i] = NULL;
			}
			else
				mvwprintw(this->_win, this->_bullets[i]->getY(), this->_bullets[i]->getX(), (char *)this->_bullet.c_str());
			tmp = 0;
			//wmove(this->_win, this->getY(), this->getX());
		}
	}
	wattroff(this->_win, COLOR_PAIR(5));
}

int		Ship::getScore(void) const
{
	return (this->_score);
}

void	Ship::addScore(int value)
{
	if (this->_score + value < 0)
		this->_score = 0;
	else
		this->_score += value;
}

int		Ship::getHP(void) const
{
	return (this->_hp);
}

std::string	Ship::getCoreIndex(int index) const
{
	return (this->_coreShip[index]);
}

void	Ship::setCoreIndex(int index, std::string str)
{
	this->_coreShip[index] = str;
}

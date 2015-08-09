/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:41:16 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/01/11 20:19:37 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include "Background.hpp"


Background::Background(int height, int base, int nbLine, WINDOW* win)
	:_maxHeight(height), _base(base), _nbLine(nbLine), _win(win), _delay(0), _speed(7)
{
	this->generateBackground();
	this->displayBackground();
	return;
}

Background::Background(void)
	:_maxHeight(25), _base(50), _nbLine(250), _delay(0), _speed(7)
{
	return;
}

Background::Background(Background const & cp)
{
	this->_maxHeight = cp.getHeight();
	this->_base = cp.getBase();
	this->_nbLine = cp.getNbLine();
	this->_win = cp.getWin();
	return;
}

Background::~Background(void)
{
	return;
}

Background const &  Background::operator=(Background const & cp)
{
	this->_maxHeight = cp.getHeight();
	this->_base = cp.getBase();
	this->_nbLine = cp.getNbLine();
	this->_win = cp.getWin();
	return(*this);
}

int	Background::getHeight(void) const
{
	return(this->_maxHeight);
}

int		Background::getBase(void) const
{
	return(this->_base);
}

int		Background::getNbLine(void) const
{
	return(this->_nbLine);
}

WINDOW	*Background::getWin(void) const
{
	return(this->_win);
}

void	Background::setWin(WINDOW *win)
{
	this->_win = win;
}

bool			Background::setDelay(void)
{
	if (this->_delay == this->_speed)
	{
		this->_delay = 0;
		return (true);
	}
	else
		this->_delay++;
	return (false);
}

void	Background::generateBackground(void)
{
	std::srand((unsigned int)std::time(NULL));
	this->_tabHeight[0] = this->_base - std::rand() % _maxHeight;
	for (int i = 1; i < this->_nbLine; i++)
	{
		this->_tabHeight[i] = this->_tabHeight[i - 1] - (std::rand() % 5 + (-2));
		if (this->_tabHeight[i] <= this->_base - this->_maxHeight)
			this->_tabHeight[i] = this->_tabHeight[i - 1] + std::rand() % 2; 
		else if(this->_tabHeight[i] >= this->_base)
			this->_tabHeight[i] = this->_tabHeight[i - 1] - std::rand() % 2;
	}
}

void	Background::displayBackground(void)
{
	init_pair(2, 18, -1);
	wattron(this->_win, COLOR_PAIR(6));
	for (int i = 0; i < this->_nbLine; i++)
	{
		for (int j = this->_base; j > this->_tabHeight[i]; j--)
			mvwprintw(this->_win, j, i, "'");
	}
	wattroff(this->_win, COLOR_PAIR(6));
}

void	Background::shiftBackground(void)
{
	if (this->setDelay())
	{
		for (int i = 0; i < this->_nbLine - 1; i++)
			this->_tabHeight[i] = this->_tabHeight[i + 1];
		this->_tabHeight[this->_nbLine - 1] = this->_tabHeight[this->_nbLine - 2] - (std::rand() % 5 + (-2));
		if (this->_tabHeight[this->_nbLine - 1] <= this->_base - this->_maxHeight)
				this->_tabHeight[this->_nbLine - 1] = this->_tabHeight[this->_nbLine - 2] + std::rand() % 2; 
		else if(this->_tabHeight[this->_nbLine - 1] >= this->_base)
				this->_tabHeight[this->_nbLine - 1] = this->_tabHeight[this->_nbLine - 2] - std::rand() % 2;
	}
	this->displayBackground();
}

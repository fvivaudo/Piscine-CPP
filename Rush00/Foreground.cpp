/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foreground.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:41:16 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/01/11 20:19:25 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include "Foreground.hpp"
#include <stdio.h>

Foreground::Foreground(int height, int base, int nbLine, WINDOW* win)
	:_minHeight(height), _base(base), _nbLine(nbLine), _win(win), _delay(0), _speed(1)
{
    this->generateForeground();
	this->displayForeground();
	return;
}

Foreground::Foreground(void)
	:_minHeight(25), _base(50), _nbLine(250), _delay(0), _speed(1)
{
	return;
}

Foreground::Foreground(Foreground const & cp)
{
	this->_minHeight = cp.getHeight();
	this->_base = cp.getBase();
	this->_nbLine = cp.getNbLine();
	this->_win = cp.getWin();
	return;
}

Foreground::~Foreground(void)
{
	return;
}

Foreground const &  Foreground::operator=(Foreground const & cp)
{
	this->_minHeight = cp.getHeight();
	this->_base = cp.getBase();
	this->_nbLine = cp.getNbLine();
	this->_win = cp.getWin();
	return(*this);
}

int	Foreground::getHeight(void) const
{
	return(this->_minHeight);
}

int		Foreground::getBase(void) const
{
	return(this->_base);
}

int		Foreground::getNbLine(void) const
{
	return(this->_nbLine);
}

WINDOW	*Foreground::getWin(void) const
{
	return(this->_win);
}

void	Foreground::setWin(WINDOW *win)
{
	this->_win = win;
}

void	Foreground::generateForeground(void)
{
	this->_tmp = 0;
	this->_equal = false;
	std::srand((unsigned int)std::time(NULL));
	this->_tabHeight[0] = std::rand() % (this->_base - this->_minHeight) + this->_minHeight;
	for (int i = 1; i < this->_nbLine; i++)
	{
		if (this->_tmp == 0)
		{
			
			if (this->_equal == false)
            {
                this->_tmp = std::rand() % 8;
				this->_equal = true;
            }
			else
            {
                this->_tmp = 1;
				this->_equal = false;
            }
		}
		else
			this->_tmp--;
		if (this->_equal)
			this->_tabHeight[i] = this->_tabHeight[i - 1];
		else
			this->_tabHeight[i] = this->_tabHeight[i - 1] - (std::rand() % 3 + (-1));
		if (this->_tabHeight[i] <= _minHeight)
			this->_tabHeight[i] = this->_tabHeight[i - 1] + std::rand() % 2;
		else if(this->_tabHeight[i] >= this->_base)
			this->_tabHeight[i] = this->_tabHeight[i - 1] - std::rand() % 2;
	}
}

bool			Foreground::setDelay(void)
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

void	Foreground::displayForeground(void)
{
	wattron(this->_win, COLOR_PAIR(1));
	for (int i = 0; i < this->_nbLine; i++)
	{
		for (int j = this->_base; j > this->_tabHeight[i]; j--)
			mvwprintw(this->_win, j, i, "^");
	}
	wattroff(this->_win, COLOR_PAIR(1));
}

void	Foreground::shiftForeground(void)
{
	if (this->setDelay())
	{
		for (int i = 0; i < this->_nbLine - 1; i++)
			this->_tabHeight[i] = this->_tabHeight[i + 1];
		if (this->_tmp == 0)
			{
				this->_tmp = std::rand() % 8;
				if (this->_equal == false)
					this->_equal = true;
				else
					this->_equal = false;
			}
			else
				this->_tmp--;
		if (this->_equal)
			this->_tabHeight[this->_nbLine - 1] = this->_tabHeight[this->_nbLine - 2];
		else
			this->_tabHeight[this->_nbLine - 1] = this->_tabHeight[this->_nbLine - 2] - (std::rand() % 3 + (-1));
		if (this->_tabHeight[this->_nbLine - 1] <= _minHeight)
				this->_tabHeight[this->_nbLine - 1] = this->_tabHeight[this->_nbLine - 2] + std::rand() % 2; 
		else if(this->_tabHeight[this->_nbLine - 1] >= this->_base)
				this->_tabHeight[this->_nbLine - 1] = this->_tabHeight[this->_nbLine - 2] - std::rand() % 2;
	}
	this->displayForeground();
}

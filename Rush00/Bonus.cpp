/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:32:57 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 13:20:18 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bonus.hpp"

Bonus::Bonus(int x, int y, WINDOW *win, int speed, std::string type, std::string str):
	_delay(0),
	_speed(speed),
	_up(1),
	_baseY(y),
	_type(type)
{
	Ship::_x = x;
	Ship::_y = y;
	Ship::_win = win;
	Ship::_coreShip[0] = str;
	srand(time(NULL));
	return ;
}

Bonus::Bonus(Bonus const & src):
	Ship(src)
{
	Ship::_x = src.getX();
	Ship::_y = src.getY();
	Ship::_win = src.getWin();
	Ship::_coreShip[0] = src.getCoreIndex(0);
	this->_type = src.getType();
	this->_delay = src.getDelay();
	this->_speed = src.getSpeed();
}

Bonus::~Bonus(void)
{
	return ;
}

Bonus const &	Bonus::operator=(Bonus const & rhs)
{
	*this = rhs;
	return (*this);
}

std::string	Bonus::getType(void) const
{
	return (this->_type);
}

bool			Bonus::setDelay(void)
{
	if (this->_delay >= 0)
	{
		this->_delay++;
		return (false);
	}
	else
	{
		this->_delay++;
		if (this->_delay == 0)
			this->_x = 500;
		return (false);
	}
}

void			Bonus::move(Ship *s)
{
	wattron(this->_win, COLOR_PAIR(7));
	if (this->_x > 1 && this->_x <= 240 && this->_delay >= 0)
	{
		if ((this->_x == s->getX() || this->_x == s->getX() + 1)
				&& (this->_y == s->getY() || this->_y == s->getY() + 1 ||
					this->_y == s->getY() - 1))
		{
			s->setFiringMod(s->getFiringMod() + 1);
			s->setBonus(this->_type);
			this->_delay = -15;
		}
		this->setX(this->getX() - 1);
		mvwprintw(this->_win, this->getY(), this->getX(), this->getCoreIndex(0).c_str());
	}
	else if (this->_delay >= 0)
	{
		if (this->_x > 240/* && s->getScore() <= 1000*/)
			this->_x--;
		else/* if (s->getScore() <= 1000)*/
		{
			this->_x = 280;
			this->_y = rand() % 35 + 2;
			this->_speed = rand() % 3 + 1;
			s->addScore(-50);
		}
	}
	else
		this->setDelay();
	wattroff(this->_win, COLOR_PAIR(7));
}

int				Bonus::getDelay(void) const
{
	return (this->_delay);
}

int				Bonus::getSpeed(void) const
{
	return (this->_speed);
}

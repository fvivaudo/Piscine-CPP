/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:32:57 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 11:40:43 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"

Boss::Boss(int x, int y, WINDOW *win, int speed):
	_delay(0),
	_speed(speed),
	_baseY(y),
	_limitX(140)
{
	Ship::_x = x;
	Ship::_y = y;
	Ship::_index = 5;
	Ship::_win = win;
	Ship::_coreShip[0] = "=||||\\";
	Ship::_coreShip[1] = "    ----\\";
	Ship::_coreShip[2] = "    ----->";
	Ship::_coreShip[3] = "    ----/";
	Ship::_coreShip[4] = "=||||/";
	Ship::_bullet = "==";
	srand(time(NULL));
	return ;
}

Boss::Boss(Boss const & src):
	Ship(src)
{
	Ship::_x = src.getX();
	Ship::_y = src.getY();
	Ship::_index = 5;
	Ship::_win = src.getWin();
	Ship::_coreShip[0] = src.getCoreIndex(0);
	Ship::_coreShip[1] = src.getCoreIndex(1);
	Ship::_coreShip[2] = src.getCoreIndex(2);
	Ship::_coreShip[3] = src.getCoreIndex(3);
	Ship::_coreShip[4] = src.getCoreIndex(4);
	this->_limitX = src.getLimitX();
	this->_delay = src.getDelay();
	this->_speed = src.getSpeed();
}

Boss::~Boss(void)
{
	return ;
}

int		Boss::getLimitX(void) const
{
	return (this->_limitX);
}

Boss const &	Boss::operator=(Boss const & rhs)
{
		*this = rhs;
	return (*this);
}

void	Boss::createBullet(void)
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
		if (this->getCoreIndex(0) == "=||||\\")
			this->_bullets[i] = new Shoot(this->_x, this->_y - std::floor(this->_index / 2), 2, 0);
		if (this->getCoreIndex(4) == "=||||/")
			this->_bullets[i + 1] = new Shoot(this->_x, this->_y + std::floor(this->_index / 2), 2, 0);
	}
}

bool			Boss::setDelay(void)
{
	if (this->_delay == this->_speed)
	{
		if (rand() % 5 == 1 && this->_x > 125)
			this->createBullet();
		this->_delay = 0;
		return (true);
	}
	else if (this->_delay >= 0)
	{
		this->_delay++;
		return (false);
	}
	else
	{
		mvwprintw(this->_win, this->getY() + 1, this->getX(), "/|\\");
		mvwprintw(this->_win, this->getY() - 1, this->getX(), "\\|/");
		mvwprintw(this->_win, this->getY(), this->getX(), "-  -");
		return (false);
	}
}

void			Boss::move(Ship *s)
{
	wattron(this->_win, COLOR_PAIR(3));
	if (this->_x > 1 && this->_x <= 240 && this->_delay >= 0)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (s->getBulletsBis(i))
			{

				if ((this->_x == s->getBulletsBis(i)->getX() || this->_x + 1 == s->getBulletsBis(i)->getX()))
				{
					if (this->_y + std::floor(this->_index / 2) == s->getBulletsBis(i)->getY())
						this->setCoreIndex(4, "x----/");
					else if (this->_y - std::floor(this->_index / 2) == s->getBulletsBis(i)->getY())
						this->setCoreIndex(0, "x----\\");
					else if (this->getCoreIndex(0) == "x----\\" && this->getCoreIndex(4) == "x----/" \
							&& this->_y - std::floor(this->_index / 2) <= s->getBulletsBis(i)->getY() \
							&& this->_y + std::floor(this->_index / 2) >= s->getBulletsBis(i)->getY())
					{
						this->die(s, i);
						return ;
					}
				}
			}
		}
		if (this->_x == s->getX() + 1 && this->_y == s->getY())
		{
			s->addScore(100);
			this->_delay = -15;
		}
		else if (this->_x == s->getX() + 1 && this->_y - 1 == s->getY() + 2)
		{
			s->addScore(100);
			this->_delay = -15;
		}
		if (this->setDelay() && this->getX() > this->_limitX)
			this->setX(this->getX() - 1);
		mvwprintw(this->_win, this->getY() - 1, this->getX(), this->getCoreIndex(1).c_str());
		mvwprintw(this->_win, this->getY() - 2, this->getX(), this->getCoreIndex(0).c_str());
		mvwprintw(this->_win, this->getY() + 2, this->getX(), this->getCoreIndex(4).c_str());
		mvwprintw(this->_win, this->getY(), this->getX(), this->getCoreIndex(2).c_str());
		mvwprintw(this->_win, this->getY() + 1, this->getX(), this->getCoreIndex(3).c_str());
	}
	else if (this->_delay >= 0)
	{
		if (this->_x > 240)
			this->_x--;
		else
		{
			this->_x = 280;
			this->_y = rand() % 35 + 2;
			this->_speed = rand() % 3 + 1;
			s->addScore(-50);
		}
	}
	else
		this->setDelay();
	this->moveBullets();
	wattroff(this->_win, COLOR_PAIR(3));
}

void			Boss::moveBullets(void)
{
	for(int i= 0; i < 1000; i++)
	{
		if (this->_bullets[i] != NULL)
		{
			this->_bullets[i]->setX(this->_bullets[i]->getX() - 1);
			wmove(this->_win, this->_bullets[i]->getY(), this->_bullets[i]->getX());
			waddstr(this->_win, (char *)this->_bullet.c_str());
			if (this->_bullets[i]->getX() <= 0)
			{
				delete this->_bullets[i];
				this->_bullets[i] = NULL;
			}
		}
	}
}

void			Boss::die(Ship *s, int i)
{
	this->_delay = -15;
	delete s->getBulletsBis(i);
	s->setBulletNull(i);
	s->addScore(100);
}

int				Boss::getDelay(void) const
{
	return (this->_delay);
}

int				Boss::getSpeed(void) const
{
	return (this->_speed);
}

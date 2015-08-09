/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:32:57 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 09:42:43 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

int		Enemy::nb_dead = 0;

Enemy::Enemy(int x, int y, WINDOW *win, int speed):
	_delay(0),
	_speed(speed),
	_baseY(y),
	_up(1),
	_dead(1)
{
	Ship::_x = x;
	Ship::_y = y;
	Ship::_win = win;
	Ship::_coreShip[0] = "<\\";
	Ship::_coreShip[1] = "</";
	Ship::_bullet = "*";
	srand(time(NULL));
	return ;
}

Enemy::Enemy(Enemy const & src):
	Ship(src)
{
	*this = src;
	this->_delay = src.getDelay();
	this->_speed = src.getSpeed();
}

Enemy::~Enemy(void)
{
	return ;
}

Enemy const &	Enemy::operator=(Enemy const & rhs)
{
	Ship::_x = rhs.getX();
	Ship::_y = rhs.getY();
	Ship::_win = rhs.getWin();
	Ship::_coreShip[0] = rhs.getCoreIndex(0);
	Ship::_coreShip[1] = rhs.getCoreIndex(1);
	return (*this);
}

bool			Enemy::setDelay(void)
{
	if (this->_delay == this->_speed)
	{
		if (rand() % 60 == 1 && this->_x > 125)
			this->createBullet(1, 0);
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
		mvwprintw(this->_win, this->getY(), this->getX(), "/|\\");
		mvwprintw(this->_win, this->getY() - 1, this->getX(), "\\|/");
		this->_delay++;
		//this->_dead = 1;
		//Respawn coordinates
	//	if (this->_delay == 0)
	//		this->spawn();
		return (false);
	}

}

void			Enemy::spawn(void)
{
	static	int pos = 0;
	static	int spawn = 0;
	static	int r = 0;

	if (nb_dead == 30) //signal start of wave of 10 enemies
	{
		spawn = 1;
		r = rand() % 35 + 2;
	}
	else if (nb_dead == 0) //end of wave sumonning
	{
		spawn = 0;
		pos = 0;
	}
	if ((nb_dead == 30 || spawn == 1) && this->_dead == 1)
	{
		this->_dead = 0;
		this->_x = 250 + pos * 2;
		this->_baseY = 20;
		this->_y = 20;
		this->_up = 1;
		this->_speed = 1;
		++pos;
	}
}

void			Enemy::move(Ship *s)
{
	wattron(this->_win, COLOR_PAIR(3));
	if (this->_x > 1 && this->_x <= 240 && this->_delay >= 0)
	{
		//check death
		for (int i = 0; i < 1000; i++)
		{
			if (s->getBulletsBis(i))
			{
				if ((this->_x == s->getBulletsBis(i)->getX()
							|| this->_x + 1 == s->getBulletsBis(i)->getX())
					&& (this->_y == s->getBulletsBis(i)->getY()
							|| this->_y - 1 == s->getBulletsBis(i)->getY()))
				{
					this->_dead = 1;
					this->die(s, i);
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
		/* PATTERN */
		if (this->setDelay())
		{
			if (this->_baseY - this->getY() > 10 || this->getY() < 2)
				this->_up = 0;
			else if (this->_baseY - this->getY() < -10 || this->getY() > 48)
				this->_up = 1;
			if (this->_up)
				this->setY(this->getY() - 1);
			else
				this->setY(this->getY() + 1);
			this->setX(this->getX() - 1);
		}
		mvwprintw(this->_win, this->getY() - 1, this->getX(), this->getCoreIndex(0).c_str());
		mvwprintw(this->_win, this->getY(), this->getX(), this->getCoreIndex(1).c_str());
	}
	else if (this->_delay >= 0)
	{
		if (this->_x > 240)
			this->_x--;
		else
		{
		//	++nb_dead;
			this->_dead = 1;
		//	this->spawn();
			//	this->_x = 280;
			//	this->_y = rand() % 35 + 2;
			//	this->_speed = rand() % 3 + 1;
				s->addScore(-50);
		}
	}
	else
		this->setDelay();
	this->moveBullets();
	wattroff(this->_win, COLOR_PAIR(3));
}

void			Enemy::moveBullets(void)
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

void			Enemy::die(Ship *s, int i)
{
	this->_dead = 1;
	this->_delay = -15;
	delete s->getBulletsBis(i);
	s->setBulletNull(i);
	s->addScore(100);
}

int				Enemy::getDead(void) const
{
	return (this->_dead);
}


int				Enemy::getDelay(void) const
{
	return (this->_delay);
}

int				Enemy::getSpeed(void) const
{
	return (this->_speed);
}

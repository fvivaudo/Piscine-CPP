/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:32:35 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/01/10 14:59:48 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Shoot.hpp"
#include "Ship.hpp"

Shoot::Shoot(int x, int y, int d_x, int d_y)
	:_x(x), _y(y), _d_x(d_x), _d_y(d_y)
{
	return;
}

Shoot::Shoot(Shoot const & cp)
{
	this->_x = cp.getX();
	this->_y = cp.getY();
	return;
}

Shoot::~Shoot(void)
{
	return;
}

Shoot const & Shoot::operator=(Shoot const & cp)
{
	this->_x = cp.getX();
	this->_y = cp.getY();
	return(*this);
}

int		Shoot::getd_X(void) const
{
	return(this->_d_x);
}
int		Shoot::getd_Y(void) const
{
	return(this->_d_y);
}

int		Shoot::getX(void) const
{
	return(this->_x);
}

int		Shoot::getY(void) const
{
	return(this->_y);
}

void	Shoot::setX(int x)
{
	this->_x = x;
}

void	Shoot::setY(int y)
{
	this->_y = y;
}

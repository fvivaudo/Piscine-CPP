/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:03:20 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 13:08:08 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_H
# define SHIP_H

#include <string>
#include <ncurses.h>
#include "Shoot.hpp"

class Ship
{
	public:
		Ship(int x, int y, WINDOW *win, std::string *tab, std::string bullet);
		Ship(void);
		Ship(Ship const &);
		virtual ~Ship(void);
		Ship const & operator=(Ship const &);
		int	getFiringMod() const;
		int	getX() const;
		int	getY() const;
		void	setFiringMod(int f);
		void	setX(int x);
		void	setY(int Y);
		std::string	**getCoreShip(void) const;
		WINDOW *getWin(void) const;
		void	setWin(WINDOW *win);
		bool	moveShip(int x, int y);
		void	createBullet(int d_x, int d_y);
		bool	getBullets(void) const;
		Shoot	*getBulletsBis(int) const;
		int		getIndex(void) const;
		void	setBulletNull(int);
		void	moveBullets(void);
		int		getScore(void) const;
		void	addScore(int);
		int		getHP(void) const;
		std::string	getCoreIndex(int) const;
		void	setCoreIndex(int index, std::string str);
		std::string		getBonus(int index) const;
		void			setBonus(std::string str);

	protected:
		int	_x;
		int	_y;
		WINDOW *_win;
		int	_score;
		int	_index;
		std::string	_coreShip[5];
		std::string	_tabBonus[4];
		Shoot	*_bullets[1000];
		std::string	_bullet;
		int	_hp;
		int _firing_mod;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:31 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 09:27:03 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include <string>
#include <ncurses.h>
#include <cstdlib>
#include "Ship.hpp"

class Enemy : public Ship
{
	private:
		int			_delay; //time between bullets
		int			_speed;
		int			_baseY; //base height
		int			_up;	//direction (up/down)
		int			_dead;
		std::string	_ship;
		std::string	_shipTop;

	public:
		static int nb_dead;
		Enemy(int x, int y, WINDOW *win, int speed);
		Enemy(void);
		Enemy(Enemy const &);
		~Enemy(void);
		Enemy const &	operator=(Enemy const &);
		void			spawn(void);
		bool			setDelay(void);
		void			move(Ship *s);
		void			die(Ship *s, int i);
		int				getDead(void) const;
		int				getDelay(void) const;
		int				getSpeed(void) const;
		virtual void	moveBullets(void);
};

#endif

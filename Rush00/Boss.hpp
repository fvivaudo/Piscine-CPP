/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:31 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 10:25:11 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_H
# define BOSS_H

#include <string>
#include <ncurses.h>
#include <cstdlib>
#include "Ship.hpp"
#include <cmath>

class Boss : public Ship
{
	private:
		int			_delay;
		int			_speed;
		int			_baseY;
		int			_limitX;
		std::string	_ship;
		std::string	_shipTop;

	public:
		Boss(int x, int y, WINDOW *win, int speed);
		Boss(void);
		Boss(Boss const &);
		~Boss(void);
		Boss const &	operator=(Boss const &);
		bool			setDelay(void);
		void			move(Ship *s);
		void			die(Ship *s, int i);
		int				getDelay(void) const;
		int				getSpeed(void) const;
		int				getLimitX(void) const;
		void			createBullet(void);
		virtual void	moveBullets(void);
};

#endif

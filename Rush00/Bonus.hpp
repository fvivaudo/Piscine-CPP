/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:26:31 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/06/21 13:20:28 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

#include <string>
#include <ncurses.h>
#include <cstdlib>
#include "Ship.hpp"

class Bonus : public Ship
{
	private:
		int			_delay;
		int			_speed;
		int			_up;
		int			_baseY;
		std::string	_type;
		std::string	_ship;
		std::string	_shipTop;

	public:
		Bonus(int x, int y, WINDOW *win, int speed, std::string type, std::string str);
		Bonus(void);
		Bonus(Bonus const &);
		~Bonus(void);
		Bonus const &	operator=(Bonus const &);
		bool			setDelay(void);
		void			move(Ship *s);
		int				getDelay(void) const;
		int				getSpeed(void) const;
		std::string		getType(void) const;
};

#endif

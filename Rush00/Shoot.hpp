/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:27:55 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/01/10 15:01:54 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_H
# define SHOOT_H

#include <ncurses.h>

class Shoot
{
	public:
		Shoot(int x, int y, int d_x, int d_y);
		Shoot(Shoot const &);
		~Shoot(void);
		Shoot	const & operator=(Shoot const &);
		int		getX(void) const;
		int		getY(void) const;
		int		getd_X(void) const;
		int		getd_Y(void) const;
		void	setY(int y);
		void	setX(int x);
	private:
		int	_x;
		int	_y;
		int _d_x;
		int _d_y;
};

#endif

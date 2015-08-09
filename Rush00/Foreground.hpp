/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foreground.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:26:46 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/01/11 17:20:29 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOREGROUND_H
# define FOREGROUND_H

#include <ncurses.h>

class Foreground
{

	private:
		int	_minHeight;
		int	_base;
		int	_nbLine;
		WINDOW *_win;
		int	_tabHeight[250];
		int	_tmp;
		bool	_equal;
		int	_delay;
		int	_speed;

	public:
		Foreground(int, int, int, WINDOW*);
		Foreground(void);
		Foreground(Foreground const &);
		~Foreground(void);
		Foreground const & operator=(Foreground const &);
		void	displayForeground(void);
		void	generateForeground(void);
		void	shiftForeground(void);
		int		getHeight(void) const;
		int		getBase(void) const;
		int		getNbLine(void) const;
		WINDOW *getWin(void) const;
		void	setWin(WINDOW *win);
		bool	setDelay(void);
};

#endif

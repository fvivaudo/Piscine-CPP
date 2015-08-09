/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:26:46 by cbarbisa          #+#    #+#             */
/*   Updated: 2015/01/11 17:26:36 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
# define BACKGROUND_H

#include <ncurses.h>

class Background
{
	private:
		int	_maxHeight;
		int	_base;
		int	_nbLine;
		WINDOW *_win;
		int	_tabHeight[250];
		int	_delay;
		int	_speed;
	public:
		Background(int, int, int, WINDOW*);
		Background(void);
		Background(Background const &);
		~Background(void);
		Background const & operator=(Background const &);
		void	displayBackground(void);
		void	generateBackground(void);
		void	shiftBackground(void);
		int		getHeight(void) const;
		int		getBase(void) const;
		int		getNbLine(void) const;
		WINDOW *getWin(void) const;
		void	setWin(WINDOW *win);
		bool	setDelay(void);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 21:24:20 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 21:33:24 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include "IModule.hpp"
#include <SFML/Graphics.hpp>

class RAMModule : public IModule
{
	public:
		RAMModule();

		void				update();
		void				update(sf::RenderWindow & window);
		void				displayTerm();
		long double			*getMem();

		~RAMModule();

	private:
		RAMModule(RAMModule const & src);
		RAMModule&			operator=(RAMModule const & rhs);

		long double	*_mem;
};


#endif

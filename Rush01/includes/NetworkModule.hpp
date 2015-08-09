/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 22:30:17 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 22:02:15 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include "IModule.hpp"
# include <SFML/Graphics.hpp>

class NetworkModule : public IModule
{
	public:
		NetworkModule();

		void				update();
		void				displayTerm();
		void				displayGraph(sf::RenderWindow & window);

		~NetworkModule();

	private:
		NetworkModule(NetworkModule const & src);
		NetworkModule&		operator=(NetworkModule const & rhs);

		long double				*_totalIO;
};

#endif

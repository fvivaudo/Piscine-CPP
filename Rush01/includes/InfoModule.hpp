/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:22:17 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 19:01:24 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOMODULE_HPP
# define INFOMODULE_HPP

# include "IModule.hpp"
# include <SFML/Graphics.hpp>

class InfoModule : public IModule
{
	public:
		InfoModule();

		void					update();
		void					displayTerm();
		void					printInfo();
		void					InfoGraph(sf::RenderWindow & window);
		std::string				getUsername();
		std::string				getHostname();
		std::string				getSysname();
		std::string				getRelease();
		std::string				getMachine();
		std::string				getOsname();
		std::string				getDate();

		~InfoModule();

	private:
		InfoModule(InfoModule const & src);
		InfoModule&			operator=(InfoModule const & rhs);
		std::string				_gUsername;
		std::string				_gHostname;
		std::string				_gSysname;
		std::string				_gRelease;
		std::string				_gMachine;
		std::string				_gOsname;
		std::string				_gDate;
};

#endif

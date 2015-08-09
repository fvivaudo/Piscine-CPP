/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:09:12 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 21:19:29 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_MODULE_HPP
# define CPU_MODULE_HPP

# include <IModule.hpp>
# include <SFML/Graphics.hpp>

class CPUModule : public IModule
{
	public:
		CPUModule();

		void				update(sf::RenderWindow & window);
		void				update();
		void				displayTerm();
		float				_getCpuFrequency(unsigned int core);
		int					_getNbCores();
		char*				_getMaxFreq();
		char*				_getBrandName();

		~CPUModule();

	private:
		CPUModule(CPUModule const & src);
		CPUModule&			operator=(CPUModule const & rhs);
		host_cpu_load_info	_getInstantCpuLoad();

		int				_gNbCores;
		char*			_gMaxFreq;
		char*			_gBrandName;
		float			_gProgBar;
};

#endif

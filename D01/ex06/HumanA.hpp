/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:06:51 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 19:06:54 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_H
# define HUMANA_H
# include <string>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon& w);
	~HumanA(void);
	void	attack(void);
	void	setWeapon(Weapon &w);


private:
	std::string	_name;
	Weapon	&	_w;


};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:06:34 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 19:06:35 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H
# define WEAPON_H
# include <string>

class Weapon
{

public:
	Weapon(std::string name);
	~Weapon(void);
	std::string&	getType(void);
	void			setType(std::string newtype);
private:
	std::string		_type;
};

#endif
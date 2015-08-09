/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:45 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:46 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>
class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string name, int hp, int max_hp, int mana, int max_mana, int level, int melee, int ranged, int armor);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap &	operator=( ClapTrap const & rhs );
	std::string	name;
	unsigned	int hp;
	unsigned	int max_hp;
	unsigned	int mana;
	unsigned	int max_mana;
	unsigned	int level;
	unsigned	int melee;
	unsigned	int ranged;
	unsigned	int armor;

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif
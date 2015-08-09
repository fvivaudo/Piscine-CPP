/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:45 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:46 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef 	SCAVTRAP_HPP
# define 	SCAVTRAP_HPP

# include <iostream>
class ScavTrap
{
public:
	ScavTrap(void);
		ScavTrap(std::string n);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		ScavTrap &	operator=( ScavTrap const & rhs );
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(std::string const & target);

	std::string	name;
	unsigned	int hp;
	unsigned	int max_hp;
	unsigned	int mana;
	unsigned	int max_mana;
	unsigned	int level;
	unsigned	int melee;
	unsigned	int ranged;
	unsigned	int armor;
};

#endif
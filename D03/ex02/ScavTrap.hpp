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
# include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
		ScavTrap(std::string n);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		ScavTrap &	operator=( ScavTrap const & rhs );
	void	challengeNewcomer(std::string const & target);
};

#endif
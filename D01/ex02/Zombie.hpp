/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:29:31 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 11:29:32 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>

class Zombie
{
public:
	
	Zombie(std::string Name = "Default", std::string Type = "lurker");
	~Zombie(void);

	void	announce( void ) const;

	std::string		name;
	std::string		type;
};

#endif
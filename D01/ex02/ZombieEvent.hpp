/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:29:54 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 11:29:54 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H
# include <string>

class ZombieEvent
{

public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void	setZombieType(std::string Type);
	Zombie* newZombie(std::string Name);
	void randomChump(void) const;

private:
	std::string		type;
	std::string		name;
};

#endif
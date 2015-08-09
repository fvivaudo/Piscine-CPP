/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:46:41 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 16:46:43 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMAN_H
# define HUMAN_H
# include "brain.hpp"
# include <string>

class Human
{
public:
	
	Human(void);
	~Human(void);
	std::string		identify(void) const;
	Brain	const&	getBrain(void) const;

private:
	const	Brain	b;
};

#endif
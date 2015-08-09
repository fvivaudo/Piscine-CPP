/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 13:18:44 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/15 13:18:46 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class Phone {

public:

	std::string		_first;
	std::string		_last;
	std::string		_nickname;
	std::string		_login;
	std::string		_postal;
	std::string		_email;
	std::string		_phone;
	std::string		_birthday;
	std::string		_favorite;
	std::string		_meal;
	std::string		_underwear;
	std::string		_secret;

	Phone (void);
	~Phone (void);
};

#endif
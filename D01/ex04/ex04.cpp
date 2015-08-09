/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:05 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/16 16:34:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>

int main(void)
{
	std::string  str = "HI THIS IS BRAIN";

	std::string* strptr = &str;
	std::string& strref = str;

	std::cout << *strptr << std::endl;
	std::cout << strref << std::endl;
	return (0);
}
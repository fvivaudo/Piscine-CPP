/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/18 21:42:52 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	bitnum = 8;

Fixed::Fixed(void) : _foo(0)
{
	std::cout << "Default Constructor called" << std::endl;

	return;
}

Fixed::Fixed(int const n) : _foo(n)
{
	std::cout << "Parametric Constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_foo);
}

void Fixed::setRawBits( int newfoo )
{
	this->_foo = newfoo;

	return;
}

Fixed &		Fixed::operator=( Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_foo = rhs.getRawBits();
	return *this;	
}

std::ostream &		operator<<( std::ostream & o, Fixed const & i)
{
	o << "The value of _foo is : " << i.getRawBits();

	return  o;	
}

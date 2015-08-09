/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:52 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:53 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_bitnum = 8;

Fixed::Fixed(void) : _foo(0)
{
	std::cout << "Default Constructor called" << std::endl;

	return;
}

Fixed::Fixed(int const n) : _foo(n)
{
	std::cout << "Int Constructor called" << std::endl;
	this->_foo = (n * (1 << _bitnum));
	return;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float Constructor called" << std::endl;
	this->_foo = roundf((n * (1 << _bitnum)));
	return;
}

Fixed::Fixed(Fixed const & src)
{
	//std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}


float Fixed::toFloat( void ) const
{
	//float res;

	//res
	// (this->getRawBits() & ((1 << _bitnum) - 1));
	return  ((float)(this->_foo) / (1 << _bitnum));
}

int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> _bitnum);
}

int Fixed::getRawBits( void ) const
{
//	std::cout << "getRawBits member function called" << std::endl;

	return (this->_foo);
}

void Fixed::setRawBits( int newfoo )
{
	this->_foo = newfoo;

	return;
}

Fixed &		Fixed::operator=( Fixed const & rhs)
{
//	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_foo = rhs.getRawBits();
	return *this;
}

float		Fixed::operator+(Fixed const &P2) const
{
	return(this->toFloat() + P2.toFloat());
}

float		Fixed::operator-(Fixed const &P2) const
{
	return(this->toFloat() - P2.toFloat());
}

float		Fixed::operator*(Fixed const &P2) const
{
	return(this->toFloat() * P2.toFloat());
}

float		Fixed::operator/(Fixed const &P2) const
{
	return(this->toFloat() / P2.toFloat());
}

bool		Fixed::operator>(Fixed const &P2) const
{
	return(this->_foo > P2._foo);
}

bool		Fixed::operator>=(Fixed const &P2) const
{
	return(this->_foo >= P2._foo);
}

bool		Fixed::operator<(Fixed const &P2) const
{
	return(this->_foo < P2._foo);
}

bool		Fixed::operator<=(Fixed const &P2) const
{
	return(this->_foo <= P2._foo);
}

bool		Fixed::operator!=(Fixed const &P2) const
{
	return(this->_foo != P2._foo);
}

bool		Fixed::operator==(Fixed const &P2) const
{
	return(this->_foo == P2._foo);
}

Fixed&		Fixed::operator++()
{
	//std::cout << "Pre incrementation operator called" << std::endl;
	this->_foo++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	//std::cout << "Post incrementation operator called" << std::endl;
  Fixed tmp(*this);
  operator++(); // prefix-increment this instance
  return (tmp);   // return value before increment
}

Fixed&		Fixed::operator--()
{
	//std::cout << "Pre incrementation operator called" << std::endl;
	this->_foo--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	//std::cout << "Post incrementation operator called" << std::endl;
  Fixed tmp(*this);
  operator--(); // prefix-increment this instance
  return (tmp);   // return value before increment
}


Fixed	const &		Fixed::max( Fixed const &P1, Fixed const &P2)
{
	if (P1 > P2)
		return (P1);
	return (P2);	
}

Fixed&		Fixed::max( Fixed &P1, Fixed &P2)
{
	if (P1 > P2)
		return (P1);
	return (P2);
}

Fixed	const &		Fixed::min( Fixed const &P1, Fixed const &P2)
{
	if (P1 < P2)
		return (P1);
	return (P2);
}

Fixed&		Fixed::min( Fixed &P1, Fixed &P2)
{
	if (P1 < P2)
		return (P1);
	return (P2);
}

std::ostream &		operator<<( std::ostream & o, Fixed const & i)
{
	o << (i.toFloat()) ;

	return  o;	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:45 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/17 11:59:46 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H

# include <iostream>
class Fixed
{
public:
	Fixed(void);
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const & src);
	~Fixed(void);

	bool			operator>(Fixed const &P2) const;
	bool			operator>=(Fixed const &P2) const;
	bool			operator<(Fixed const &P2) const;
	bool			operator<=(Fixed const &P2) const;
	bool			operator!=(Fixed const &P2) const;
	bool			operator==(Fixed const &P2) const;
	Fixed&			operator=( Fixed const & rhs );
	float			operator-( Fixed const & rhs ) const;
	float			operator+( Fixed const & rhs ) const;
	float			operator*( Fixed const & rhs ) const;
	float			operator/( Fixed const & rhs ) const;
	Fixed&			operator++();
	Fixed			operator++(int);
	Fixed&			operator--();
	Fixed			operator--(int);

	int				toInt( void ) const;
	float 			toFloat( void ) const;
	int 			getRawBits( void ) const;
	void 			setRawBits( int newfoo );

	static	Fixed	const	&		max( Fixed const &P1, Fixed const &P2);
	static				Fixed&		max( Fixed &P1, Fixed &P2);
	static	Fixed	const	&		min( Fixed const &P1, Fixed const &P2);
	static				Fixed&		min( Fixed &P1, Fixed &P2);
private:
	static const int	_bitnum;

	int	_foo;
};

std::ostream &		operator<<(std::ostream & o, Fixed const & i);

#endif
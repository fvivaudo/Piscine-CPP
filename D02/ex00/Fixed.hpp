/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:59:45 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/18 21:41:01 by fvivaudo         ###   ########.fr       */
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
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=( Fixed const & rhs );

	int getRawBits( void ) const;
	void setRawBits( int newfoo );
private:
	static const int	bitnum;
	int	_foo;
};

std::ostream &		operator<<(std::ostream & o, Fixed const & i);
#endif

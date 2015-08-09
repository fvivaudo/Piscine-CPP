/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 20:53:57 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/06/25 20:53:58 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

template <typename T>
class Array
{
public:
	Array(void);
	Array(unsigned int n);
	~Array(void);
	T & operator[](unsigned int i);
	Array &	operator=( Array const & rhs );
	Array(Array const & src);
	unsigned int size(void);
private:
	unsigned int _size;
	T * _s;
};

template <typename T>
unsigned int Array<T>::size(void)
{
	return (this->_size);
}

template <typename T>
Array<T>::Array(Array const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_s = new T[src._size];
	*this = src;
}

template <typename T>
Array<T>::Array(void) : _size(0)
{
	std::cout << "Array constructed" << std::endl;
	this->_s = new T[0];
	return;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "Array constructed" << std::endl;
	this->_s = new T[n];
	return;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array destroyed" << std::endl;
	if (this->_size > 0)
	{
		this->_size = 0;
	}
}

template <typename T>
T & Array<T>::operator[](unsigned int i)
{
		if (i > _size)
		{
			throw std::out_of_range ("Out of Range");
				return (this->_s[0]);
		}
	return (this->_s[i]);
}

template <typename T>
Array<T> &	Array<T>::operator=( Array const & rhs )
{
	std::cout << "Assignement operator called" << std::endl;
	unsigned int i = 0;
	while (i < rhs._size)
	{
		this->_s[i] = rhs._s[i];
		++i;
	}
	this->_size = rhs._size;
	return (*this);
}


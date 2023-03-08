/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:09:05 by klew              #+#    #+#             */
/*   Updated: 2023/03/08 11:32:46 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( const int value )
{
	std::cout << "Constant integer constructor called" << std::endl;
	this->_fixedPointValue = value << this->_numFractBits;
	return;
}

Fixed::Fixed( const float value )
{
	int power = pow(2, this->_numFractBits);

	std::cout << "Constant float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * power);
	return;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignement operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs._fixedPointValue;
	return *this;
}

int	Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> this->_numFractBits);
}

float	Fixed::toFloat( void ) const
{
	int		power = pow(2, this->_numFractBits);
	float	result = (float)this->_fixedPointValue / power;
	return (result);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( const int raw )
{
	this->_fixedPointValue = raw;
}

std::ostream &	operator<<( std::ostream & ostr, Fixed const & instance)
{
	ostr << instance.toFloat();
	return (ostr);
}

int		ft_pow(int val, int pow)
{
	int		i = 0;
	int		result;

	result = 1;
	while (i < pow)
	{
		result *= val;
		i++;
	}
	return (result);
}

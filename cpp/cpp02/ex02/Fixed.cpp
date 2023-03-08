/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:09:20 by klew              #+#    #+#             */
/*   Updated: 2023/03/08 11:32:51 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

int		Fixed::ft_pow(const int val, const int power) const
{
	int		i = 0;
	int		result;

	result = 1;
	while (i < power)
	{
		result *= val;
		i++;
	}
	return (result);
}

Fixed::Fixed( void ): _fixed_point_value(0)
{
	return;
}

Fixed::Fixed( const int value )
{
	this->_fixed_point_value = value << this->_number_of_fractional_bits;
	return;
}

Fixed::Fixed( const float value )
{
	int power = ft_pow(2, this->_number_of_fractional_bits);

	this->_fixed_point_value = roundf(value * power);
	return;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
	return;
}

Fixed::~Fixed( void )
{
	return;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
		this->_fixed_point_value = rhs._fixed_point_value;
	return *this;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->toFloat() != rhs.toFloat();
}
bool Fixed::operator==(const Fixed &rhs) const
{
	return this->toFloat() == rhs.toFloat();
}

Fixed	Fixed::operator+( const Fixed &rhs ) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( const Fixed &rhs ) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*( const Fixed &rhs ) const
{
	Fixed	result(this->toFloat() * rhs.toFloat());

	return (result);
}

Fixed	Fixed::operator/( const Fixed &rhs ) const
{
	Fixed	result(this->toFloat() / rhs.toFloat());

	return (result);
}

Fixed	&Fixed::operator++( void )
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old(*this);

	++(*this);
	return (old);
}

Fixed	&Fixed::operator--( void )
{
	this->_fixed_point_value--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	old(*this);

	--(*this);
	return (old);
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed_point_value >> this->_number_of_fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	int		power = ft_pow(2, this->_number_of_fractional_bits);
	float	result = (float)this->_fixed_point_value / power;

	return (result);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits( const int raw )
{
	this->_fixed_point_value = raw;
}

Fixed		&Fixed::min( Fixed &lhs, Fixed &rhs )
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed		&Fixed::min( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed		&Fixed::max( Fixed &lhs, Fixed &rhs )
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed		&Fixed::max( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

std::ostream &	operator<<( std::ostream & ostr, Fixed const & instance)
{
	ostr << instance.toFloat();
	return (ostr);
}

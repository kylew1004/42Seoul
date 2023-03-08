/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:09:23 by klew              #+#    #+#             */
/*   Updated: 2023/03/08 11:32:52 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

public:

	Fixed( void );
	Fixed( const int value );
	Fixed( const float value );
	Fixed( const Fixed &src );
	~Fixed( void );

	Fixed	&operator=( const Fixed &obj );
	bool	operator>( const Fixed &obj ) const ;
	bool	operator<( const Fixed &obj ) const ;
	bool	operator>=( const Fixed &obj ) const ;
	bool	operator<=( const Fixed &obj ) const ;
	bool	operator==( const Fixed &obj ) const ;
	bool	operator!=( const Fixed &obj ) const ;
	Fixed	operator+( const Fixed &obj ) const ;
	Fixed	operator-( const Fixed &obj ) const ;
	Fixed	operator*( const Fixed &obj ) const ;
	Fixed	operator/( const Fixed &obj ) const ;
	Fixed	&operator++( void );
	Fixed	operator++( int );
	Fixed	&operator--( void );
	Fixed	operator--( int );

	int		toInt( void ) const;
	float	toFloat( void ) const;

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );

	static Fixed		&min( Fixed &ref, Fixed &obj );
	static const Fixed	&min( const Fixed &ref, const Fixed &obj );
	static Fixed		&max( Fixed &ref, Fixed &obj );
	static const Fixed	&max( const Fixed &ref, const Fixed &obj );

private:

	int					_fixed_point_value;
	static const int	_number_of_fractional_bits = 8;
	int					ft_pow(const int val, const int pow) const;

};

std::ostream	&operator<<( std::ostream &ostream, const Fixed &myClass );
int				ft_pow(int val, int pow);

#endif

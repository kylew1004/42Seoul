/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:09:10 by klew              #+#    #+#             */
/*   Updated: 2023/03/08 11:32:47 by klew             ###   ########.fr       */
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

	Fixed	&operator=( const Fixed &other );

	int		toInt( void ) const;
	float	toFloat( void ) const;

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );

private:

	int					_fixedPointValue;
	static const int	_numFractBits = 8;
	int					ft_pow(int val, int pow);

};

std::ostream	&operator<<( std::ostream &ostream, const Fixed &myClass );
int				ft_pow(int val, int pow);

#endif

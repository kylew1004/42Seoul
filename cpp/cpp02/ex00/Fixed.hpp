/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:08:55 by klew              #+#    #+#             */
/*   Updated: 2023/03/08 11:32:41 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

public:

	Fixed( void );
	Fixed( const Fixed &src );
	~Fixed( void );

	Fixed	&operator=( const Fixed &obj );

	int		getRawBits( void ) const;
	void	setRawBits( const int rawBits );

private:

	int					_fixedPointValue;
	static const int	_numFractBits = 8;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:09:28 by klew              #+#    #+#             */
/*   Updated: 2023/03/08 11:32:53 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main (void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c ( -12 );

	std::cout << "a = "<< a << std::endl;
	std::cout << "b = "<< b << std::endl;
	std::cout << "c = "<< c << std::endl << std::endl;

	std::cout << "Comparison operators" << std::endl;
	std::cout << "a < c is " << (a < c) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a <= c is " << (a <= c) << std::endl;
	std::cout << "a >= c is " << (a >= c) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl << std::endl;

	std::cout << "Binary operators" << std::endl;
	std::cout << "c + a = " << (c + a) << std::endl;
	std::cout << "c - a = " << (c - a) << std::endl;
	std::cout << "c * a = " << (c * a) << std::endl;
	std::cout << "c / b = " << (c / b) << std::endl << std::endl;

	std::cout << "Unary operators" << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "Value of a is: " << a << std::endl << std::endl;

	std::cout << "Other functions" << std::endl;
	std::cout << "c.toInt() = " << c.toInt() << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << std::endl;
	std::cout << "min(a, d) = " << Fixed::min(a, c) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl << std::endl;
}
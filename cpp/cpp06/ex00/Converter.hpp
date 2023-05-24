/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:28:53 by klew              #+#    #+#             */
/*   Updated: 2023/05/24 12:14:04 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Converter_HPP
# define Converter_HPP

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <cctype>
#include <climits>

class Converter
{
	private:
		std::string	str;
		double		value;
		bool		is_nan;
		bool		is_invalid;
		bool		is_inf;

	public:
		char toChar() const;
		int toInt() const;
		float toFloat() const;
		double toDouble() const;

		std::string getStr() const;
		double getValue() const;
		bool getIsNan() const;
		bool getIsInf() const;
		bool getIsInvalid() const;

		Converter(const std::string str);
		Converter();
		Converter(const Converter& ref);
		Converter& operator=(const Converter& ref);
		~Converter();

		class NonDisplayableException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		class ImpossibleException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		class NormalException : public std::exception
		{
		private:
			const char *msg;
		public:
			const char *what() const throw();
			NormalException(const char *msg);
		};
};

std::ostream& operator<<(std::ostream& os, const Converter& ref);

#endif
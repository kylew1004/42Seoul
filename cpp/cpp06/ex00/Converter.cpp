/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:29:17 by klew              #+#    #+#             */
/*   Updated: 2023/05/23 13:14:40 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void) {
	std::cout << "default constructor is called" << std::endl;
}

Converter::Converter(const Converter& src) : double_data(src.double_data) {}
Converter::~Converter(void) {}
Converter& Converter::operator=(Converter const& rhs) {
	this->double_data = rhs.double_data;
	return *this;
}

Converter::Converter(const char *str) {
	char* endptr;
	double_data = strtod(str, &endptr);
	if (*endptr)
	{
		if (strcmp(endptr, "f"))
		{
			std::cout << "you need input number" << std::endl;
			return ;
		}
	}
		toChar();
		toInt();
		toFloat();
		toDouble();
}

void Converter::toChar(void) {
	if (32 <= double_data && double_data <= 126)
	{
		std::cout << "char: " << static_cast<char>(double_data)<< std::endl;
		return ;
	}
	if ((double_data >= 0 && double_data <= 255)) {
		std::cout << "char: " << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: " << "impossible" << std::endl;
}

void Converter::toInt(void) {
	if (double_data > INT_MAX || double_data < INT_MIN || double_data == INFINITY || isnan(double_data))
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(double_data)<< std::endl;
}

void Converter::toFloat(void) {
	std::cout << "float: " << static_cast<float>(double_data);
	if (double_data == floor(double_data) && double_data < 1000000 && double_data > -1000000)
		std::cout << ".0";
	std::cout << "f" <<std::endl;
}

void Converter::toDouble(void) {
	std::cout << "double: " << static_cast<double>(double_data);
	if (double_data == floor(double_data) && double_data < 1000000 && double_data > -1000000)
		std::cout << ".0";
	std::cout << std::endl;
}
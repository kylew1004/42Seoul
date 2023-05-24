/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:29:17 by klew              #+#    #+#             */
/*   Updated: 2023/05/24 12:40:36 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

char Converter::toChar() const
{
	if (is_nan || is_inf || is_invalid || value < 0 || value > 255)
		throw ImpossibleException();
	if (!std::isprint(static_cast<int>(value)))
		throw NonDisplayableException();
	return static_cast<char>(value);
}

int Converter::toInt() const
{
	if (is_nan || is_inf || is_invalid || (value > INT_MAX || value < INT_MIN))
		throw ImpossibleException();
	return static_cast<int>(value);
}

float Converter::toFloat() const
{
	if (is_invalid)
		throw ImpossibleException();
	if (is_nan)
		throw NormalException("nan");
	if (is_inf)
	{
		if (str == "-inf")
			throw NormalException("-inff");
		throw NormalException("+inff");
	}
	return static_cast<float>(value);
}

double Converter::toDouble() const
{
	if (is_invalid)
		throw ImpossibleException();
	if (is_nan)
		throw NormalException("nanf");
	if (is_inf)
	{
		if (str == "-inf")
			throw NormalException("-inf");
		throw NormalException("+inf");
	}
	return static_cast<double>(value);
}

std::string Converter::getStr() const
{
	return str;
}

double Converter::getValue() const
{
	return value;
}

bool Converter::getIsNan() const
{
	return is_nan;
}
bool Converter::getIsInf() const
{
	return is_inf;
}
bool Converter::getIsInvalid() const
{
	return is_invalid;
}

Converter::Converter(const std::string str)
	: str(str), value(0.0), is_nan(false), is_invalid(false), is_inf(false)
{
	if (str == "nan")
		is_nan = true;
	else if (str == "inf" || str == "-inf" || str == "+inf")
		is_inf = true;
	else if (str[0] != '-' && str[0] != '+' && !std::isdigit(static_cast<int>(str[0])))
		is_invalid = true;
	if (!is_invalid)
		value = std::atof(str.c_str());
}

Converter::Converter() : str("") {}

Converter::Converter(const Converter &ref)
{
	*this = ref;
}

Converter &Converter::operator=(const Converter &ref)
{
	str = ref.getStr();
	value = ref.getValue();
	return *this;
}

Converter::~Converter() {}

std::ostream &operator<<(std::ostream &os, const Converter &ref)
{
	if (ref.getIsInvalid())
		return os << "Only the decimal notation will be used" << std::endl;
	os << "char: ";
	try
	{
		char _c = ref.toChar();
		os <<"'" << _c <<"'" << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "int: ";
	try
	{
		os << ref.toInt() << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "float: ";
	try
	{
		os << ref.toFloat();
		if (ref.getValue() - static_cast<int>(ref.getValue()) == 0.0)
			os << ".0";
		os << 'f' << std::endl;
	}
	catch (const Converter::NormalException &e)
	{
			os << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "Double: ";
	try
	{
		os << ref.toDouble();
		if (ref.getValue() - static_cast<int>(ref.getValue()) == 0.0)
			os << ".0";
		os << std::endl;
	}
	catch (const Converter::NormalException &e)
	{
		os << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	return os;
}

const char *Converter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}

const char *Converter::ImpossibleException::what() const throw()
{
	return "impossible";
}

Converter::NormalException::NormalException(const char *msg)
{
	this->msg = msg;
}

const char *Converter::NormalException::what() const throw()
{
	return msg;
}
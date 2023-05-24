/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:53:34 by klew              #+#    #+#             */
/*   Updated: 2023/05/24 12:05:38 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer& source)
{
	Serializer	tmp;

	tmp = source;
}

Serializer& Serializer::operator=(const Serializer& source)
{
	Serializer	tmp = source;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
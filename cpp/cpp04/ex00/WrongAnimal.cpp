/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:18:55 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:53:32 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) 
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Class Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) 
{
	this->type = obj.type;
	std::cout << "WrongAnimal Class copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) 
{
	this->type = obj.type;
	std::cout << "WrongAnimal Class operator= called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "WrongAnimal Class Destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal say nothing, this message is something wrong" << std::endl;
}
std::string WrongAnimal::getType(void) const
{
	return (type);
}
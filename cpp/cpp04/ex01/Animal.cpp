/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:24:27 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:53:43 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) 
{
	this->type = "Animal";
	std::cout << "Animal Class Constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) 
{
	this->type = obj.type;
	std::cout << "Animal Class copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) 
{
	this->type = obj.type;
	std::cout << "Animal Class operator= called" << std::endl;
	return (*this);
}

Animal::~Animal(void) 
{
	std::cout << "Animal Class Destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal say nothing, this message is something wrong" << std::endl;
}

std::string Animal::getType(void) const
{
	return (type);
}
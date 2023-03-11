/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:23 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:54:20 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) 
{
	this->type = "Cat";
	std::cout << "Cat Class Constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) 
{
	this->type = obj.type;
	std::cout << "Cat Class copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) 
{
	this->type = obj.type;
	std::cout << "Cat Class operator= called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Class Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat say 'meow...'" << std::endl;
}
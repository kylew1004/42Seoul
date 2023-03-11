/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:33 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:53:26 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) 
{
	this->type = "Dog";
	std::cout << "Dog Class Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) 
{
	this->type = obj.type;
	std::cout << "Dog Class copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) 
{
	this->type = obj.type;
	std::cout << "Dog Class operator= called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Class Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog say 'Bark Bark!'" << std::endl;
}
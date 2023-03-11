/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:23:20 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:23:25 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) 
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Class Constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) 
{
	this->type = obj.type;
	this->brain = new Brain();
	*(this->brain) = *(obj.brain);
	std::cout << "Cat Class copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) 
{
	this->type = obj.type;
	*(this->brain) = *(obj.brain);
	std::cout << "Cat Class operator= called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	this->brain = NULL;
	std::cout << "Cat Class Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat say 'meow...'" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}
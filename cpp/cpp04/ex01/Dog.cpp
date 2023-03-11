/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:22:39 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:22:44 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) 
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Class Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) 
{
	this->type = obj.type;
	this->brain = new Brain();
	*(this->brain) = *(obj.brain);
	std::cout << "Dog Class copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) 
{
	this->type = obj.type;
	*(this->brain) = *(obj.brain);
	std::cout << "Dog Class operator= called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	this->brain = NULL;
	std::cout << "Dog Class Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog say 'Bark Bark!'" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
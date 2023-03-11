/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:17:56 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:53:54 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) 
{
	this->type = "WrongCat";
	std::cout << "WrongCat Class Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) 
{
	this->type = obj.type;
	std::cout << "WrongCat Class copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) 
{
	this->type = obj.type;
	std::cout << "WrongCat Class operator= called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Class Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat say 'meow...'" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:26:48 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:26:52 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) 
{
	for (size_t i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << i;
		this->ideas[i] = ss.str();
	}
	std::cout << "Brain Class Constructor called" << std::endl;	
}

Brain::Brain(const Brain& obj) 
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.getIdeas(i);
	}
	std::cout << "Brain Class copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& obj) 
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.getIdeas(i);
	}
	std::cout << "Brain Class operator= called" << std::endl;
	return (*this);
}

Brain::~Brain(void) 
{
	std::cout << "Brain Class Destructor called" << std::endl;

}

std::string Brain::getIdeas(int n) const
{
	return (this->ideas[n]);
}

void Brain::setIdeas(std::string idea, int n)
{
	if (n < 0 || n > 100)
		std::cout << "error. Brain's array size is 100." << std::endl;
	else
		this->ideas[n] = idea;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:16 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:17 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void): _name("")
{
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::_name << " passed away..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}

bool	Zombie::setName( std::string newName )
{
	if (newName == "")
		return (false);
	this->_name = newName;
	return (true);
}
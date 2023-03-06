/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:47 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:47 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon): type(weapon)
{
}

Weapon::~Weapon( void )
{
}

const	std::string &Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType( const std::string& type )
{
	this->type = type;
}
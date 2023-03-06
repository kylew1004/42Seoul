/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:37 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:37 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): name(name), weapon(nullptr)
{
}

void    HumanB::setWeapon( Weapon& newWeapon )
{
    this->weapon = &newWeapon;
}

void	HumanB::attack(void)
{
    if (this->weapon)
	    std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else
	    std::cout << this->name << " can not attack because they has no weapon" << std::endl;
}
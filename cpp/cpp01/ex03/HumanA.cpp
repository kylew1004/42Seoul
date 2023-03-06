/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:32 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:33 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

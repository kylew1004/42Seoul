/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:42 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:43 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int	main(void)
{
	{
		Weapon	arm = Weapon("shotgun");
		HumanA	bob("Bob", arm);
		bob.attack();
		arm.setType("sniper");
		bob.attack();
	}
	{
		Weapon	arm = Weapon("shotgun");
		HumanB	Jan("Jan");
		Jan.attack();
		Jan.setWeapon(arm);
		arm.setType("pistol");
		Jan.attack();
	}
}
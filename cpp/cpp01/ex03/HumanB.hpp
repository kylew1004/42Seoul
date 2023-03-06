/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:39 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:40 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;

	public:
	HumanB(std::string name);
	void	attack(void);
	void	setWeapon( Weapon& newWeapon );
};

#endif
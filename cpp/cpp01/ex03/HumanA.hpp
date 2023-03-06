/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:35 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:35 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
	std::string	name;
	Weapon		&weapon;

	public:
	HumanA ( std::string name, Weapon &weapon );
	~HumanA ( void );

	void	attack(void);
};

#endif
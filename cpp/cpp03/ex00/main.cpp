/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:14:24 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 15:57:01 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(5);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(10);
	a.beRepaired(10);
	std::cout << std::endl;

	return (0);
}
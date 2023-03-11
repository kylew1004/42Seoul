/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:14:55 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:01:29 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("A");
	FragTrap b("B");

	std::cout << std::endl;
	
	a.attack("B");
	b.takeDamage(a.getDamege());
	b.beRepaired(3);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(b.getDamege());
	a.beRepaired(10);
	std::cout << std::endl;

	a.highFivesGuys();
	std::cout << std::endl;

	return (0);
}
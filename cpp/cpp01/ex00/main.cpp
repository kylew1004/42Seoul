/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:01:54 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 13:34:25 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "This is one way to create a zombie:" << std::endl;
	Zombie zombie("Klew");
	zombie.announce();

	std::cout << "This is a dynamic zombie:" << std::endl;
	Zombie *dynamic_zombie = newZombie("Lee");
	dynamic_zombie->announce();
	delete dynamic_zombie;

	std::cout << "This zombie is a random chump:" << std::endl;
	randomChump("Kim");

	return (0);
}
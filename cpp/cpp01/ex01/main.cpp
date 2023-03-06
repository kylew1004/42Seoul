/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:12 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:12 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombies = zombieHorde(7, "Hagrid");
	for (int i = 0; i < 7; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
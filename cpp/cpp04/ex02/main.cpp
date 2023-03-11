/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:25:00 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:25:06 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal *d = new Dog();
	Animal *d2 = new Dog();
	std::string str;
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
		}
		else
		{
			meta[i] = new Cat();
		}
	}
	std::cout << std::endl;
	
	for (size_t i = 0; i < 10; i++)
	{
		delete meta[i];
	}
	

	std::cout << std::endl;
	d->makeSound();
	d2->makeSound();

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;

	return 0;
}
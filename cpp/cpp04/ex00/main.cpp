/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:17:01 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:54:09 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	std::cout << std::endl;
	delete meta;
	meta = NULL;
	delete j;
	j = NULL;
	delete i;
	i = NULL;
	delete wrong;
	wrong = NULL;
	return 0;
}
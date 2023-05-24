/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:30:12 by klew              #+#    #+#             */
/*   Updated: 2023/05/24 12:09:06 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char *av[])
{
	Data prev;
	Data *next;
	uintptr_t ptr;

	if (ac != 2)
	{
		std::cout << "argument count is not 2" << std::endl;
		return (1);
	}	
	prev.data = av[1];
	std::cout << "prev : " << prev.data << std::endl;

	ptr = Serializer::serialize(&prev);
	std::cout << "ptr : " << ptr << std::endl;

	next = Serializer::deserialize(ptr);
	std::cout << "next : " << next->data << std::endl;

	return (0);
}
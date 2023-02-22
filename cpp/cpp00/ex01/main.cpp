/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:59:52 by klew              #+#    #+#             */
/*   Updated: 2023/02/22 17:42:52 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;

	std::string command;

	while (std::cin)
	{
		std::cout << "Enter one of the three commands (ADD, SEARCH or EXIT): " << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.Add();
		else if (command == "SEARCH")
			phonebook.Search();
		else if (command == "EXIT")
			return (0);
		else
			std::cout << std::endl << "Wrong command!" << std::endl << std::endl;
	}
	return (0);
}

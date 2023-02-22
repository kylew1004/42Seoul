/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:54:25 by klew              #+#    #+#             */
/*   Updated: 2023/02/22 17:30:16 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdlib.h>

PhoneBook::PhoneBook() : _num_contacts(0), _num_Search(0) {}

void	PhoneBook::Add()
{
	Contact temp;

	temp.GetInfo();
	if (temp.CheckContact() == 1)
		return ;
	if (_num_contacts == 8)
		_num_contacts = 0;
	contact[_num_contacts] = temp;
	_num_contacts += 1;
	if (_num_Search != 8)
		_num_Search += 1;
}

void	PhoneBook::Search()
{
	int	index = -1;
	for (int i = 0; i < _num_Search; i++)
	{
		std::cout << std::endl << std::setw(10);
		std::cout << i + 1 << "|";
		contact[i].CheckAndPrint(contact[i].GetContractInfo("first_name"));
		contact[i].CheckAndPrint(contact[i].GetContractInfo("last_name"));
		contact[i].CheckAndPrint(contact[i].GetContractInfo("nickname"));
	}
	if (!_num_Search)
	{
		std::cout << std::endl << "No contacts to display, Add them first." << std::endl << std::endl;
		return ;
	}
	std::cout << std::endl << "Enter the index of the contact to display: ";
	std::cin >> index;
	if (index == -1)
		exit (1);
	else if (std::cin.fail())
		std::cout << "Your input is not valid, enter a valid index" << std::endl;
	else if (index < 1 || index > _num_Search)
		std::cout << "Your input is not valid, enter a valid index" << std::endl;
	else
		contact[index - 1].PrintContactInfo();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

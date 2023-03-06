/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:03:16 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:03:16 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	error_message(std::string error)
{
	std::cout << error << std::endl;
	return (1);
}

int main(int argc, char *argv[])
{
    Harl Harl;
	int	Level = Harl.get_level(argv[1]);
	
	if (argc != 2)
		return (error_message("Error: you did not enter the right amount of arguments"));
	switch (Level)
	{
	case 1:
		Harl.complain("debug");
		break;
	case 2:
		Harl.complain("info");
		break;
	case 3:
		Harl.complain("warning");
		break;
	case 4:
		Harl.complain("error");
		break;
	default:
		Harl.complain("pouet");
		break;
	}
	return (0);
}
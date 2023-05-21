/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:40:10 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:02:14 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat		pete("Pete", 1);
	Bureaucrat		kanye("Kanye", 40);
	Bureaucrat		kim("Kim", 150);

	try
	{
		PresidentialPardonForm fa("Condifential");
		fa.beSigned(pete);
		fa.execute(pete);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl << std::endl;

	try
	{
		PresidentialPardonForm fb("Confidential");
		fb.beSigned(pete);
		fb.execute(pete);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl << std::endl;

	try
	{
		RobotomyRequestForm fc("Divorce papers");
		fc.beSigned(pete);
		fc.execute(kanye);
		fc.execute(kanye);
		fc.execute(kanye);
		fc.execute(kanye);
		fc.execute(kanye);
		fc.execute(kanye);
		fc.execute(kanye);
		fc.execute(kanye);
		fc.execute(kanye);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl << std::endl;

	try
	{
		ShrubberyCreationForm fd("Planting plan");
		fd.beSigned(pete);
		fd.execute(kanye);
		fd.execute(kim);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
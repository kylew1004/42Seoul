/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:36:39 by klew              #+#    #+#             */
/*   Updated: 2023/05/16 13:42:38 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
    {
        Bureaucrat  bureaucrat("klew", 50);
        
        std::cout << bureaucrat << std::endl;
        
        bureaucrat.incrementGrade(5);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade(2);
        std::cout << bureaucrat << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	try
    {
        Bureaucrat  bureaucrat("curry", 0);
        
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade(3);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade(3);
        std::cout << bureaucrat << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	try
    {
        Bureaucrat  bureaucrat("lebron", 151);
        
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade(3);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade(3);
        std::cout << bureaucrat << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	return 0;
}
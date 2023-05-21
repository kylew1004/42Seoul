/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:51:49 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:01:30 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ): Form("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm( void ): Form("RobotomyRequestForm", 72, 45), _target("")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ): Form("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & obj )
{
	obj.getTarget();
	return *this;
}

const std::string	&RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}

void	RobotomyRequestForm::execute( const Bureaucrat &exec ) const
{
	this->checkExecutability(exec);
	std::cout << "* Drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized, this happens 50% of the time." << std::endl;
	else
		std::cout << "The robotomization on " << this->_target << " failed..." << std::endl;
}
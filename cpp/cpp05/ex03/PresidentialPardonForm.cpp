/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:52:17 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:01:40 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ): Form("PresidentialPardonForm", 25, 5), _target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm( void ): Form("PresidentialPardonForm", 25, 5), _target("")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ): Form("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const & obj )
{
	obj.getTarget();
	return *this;
}

const std::string	&PresidentialPardonForm::getTarget( void ) const
{
	return this->_target;
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	this->checkExecutability(executor);
	std::cout << this->_target << " has been pardoned."<< std::endl;
}
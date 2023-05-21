/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:52:49 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:01:47 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	return;
}

Intern::Intern( Intern const & src )
{
	*this = src;
	return;
}

Intern::~Intern( void )
{
	return;
}

Intern &	Intern::operator=( Intern const & ref )
{
	(void)ref;
	return *this;
}

Form	*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	t_formList forms[] = 
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};
	Form	*resultForm = NULL;

	for (int i = 0; forms[i].formType != NULL; i++)
	{
		if (forms[i].formName == formName)
			resultForm = forms[i].formType;
		else
			delete forms[i].formType;
	}
	if (resultForm == NULL)
		std::cout << "Intern did not find the form " << formName << std::endl;
	else
		std::cout << "Intern creates " << formName << std::endl;
	return resultForm;
}

std::ostream &	operator<<( std::ostream & ostr, Intern const & instance)
{
	(void)instance;
	ostr << "Intern" << std::endl;
	return ostr;
}
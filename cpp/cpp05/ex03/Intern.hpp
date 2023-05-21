/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:52:40 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:01:45 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

public:

	Intern( void );
	Intern( const Intern &src );
	~Intern( void );

	Intern	&operator=( const Intern &ref );

	Form	*makeForm(const std::string &formName, const std::string &target) const;

private:

	typedef struct	s_formList
	{
		std::string	formName;
		Form		*formType;
	}				t_formList;
};

std::ostream	&operator<<( std::ostream &ostr, const Intern &instance );

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:53:25 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:01:52 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ): _name(""), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat( const std::string &name, int grade ): _name(name), _grade(grade)
{
	checkGrade();
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat( void )
{
	return;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & ref )
{
	this->_grade = ref._grade;
	return *this;
}

const std::string	&Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade( int quantity )
{
	std::cout << "Incremented value with " << quantity << std::endl;
	this->_grade -= quantity;
	checkGrade();
}

void	Bureaucrat::decrementGrade( int quantity )
{
	std::cout << "Decremented value with " << quantity << std::endl;
	this->_grade += quantity;
	checkGrade();
}

bool	Bureaucrat::signForm( Form &form ) const
{
	if (form.beSigned(*this))
	{
		std::cout << this->_name << " signs form " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cout << this->_name << " cannot sign form " << form.getName() << " because their grade is not high enough" << std::endl;
		return false;
	}
}

void	Bureaucrat::checkGrade( void ) const
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

bool	Bureaucrat::executeForm( const Form &form ) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes form " << form.getName() << std::endl;
		return true;
	}
	catch (Form::CantExecuteForm &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
}

std::ostream &	operator<<( std::ostream & ostr, Bureaucrat const & instance)
{
	ostr << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return ostr;
}
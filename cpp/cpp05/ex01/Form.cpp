/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:22:42 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:04:04 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string &name, int gradeToSign, int gradeToExecute ):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	this->checkGrades();
	std::cout << "Standard constructor for Form called" << std::endl;
	return;
}

Form::Form( void ): _name(""), _isSigned(false),
	_gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default constructor for Form called" << std::endl;
	return;
}

Form::Form( Form const & src ): _name(src.getName()), _isSigned(src.isSigned()),
	_gradeToSign(src.getSignGrade()), _gradeToExecute(src.getExecuteGrade())
{
	std::cout << "Copy constructor for Form called" << std::endl;
	*this = src;
	return;
}

Form::~Form( void )
{
	std::cout << "Destructor for Form called" << std::endl;
	return;
}

Form	&Form::operator=( Form const & rhs )
{
	this->_isSigned = rhs._isSigned;
	std::cout << "Assignement operator for Form called" << std::endl;
	return *this;
}

const std::string	&Form::getName( void ) const
{
	return this->_name;
}

int	Form::getSignGrade( void ) const
{
	return this->_gradeToSign;
}

int	Form::getExecuteGrade( void ) const
{
	return this->_gradeToExecute;
}

bool	Form::isSigned( void ) const
{
	return this->_isSigned;
}

void	Form::checkExecutability( const Bureaucrat &bureaucrat ) const
{
	if (this->_isSigned == false || bureaucrat.getGrade() < this->_gradeToExecute)
		throw Form::CantExecuteForm();
}

void	Form::checkGrades( void ) const
{
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

bool	Form::beSigned( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() < this->_gradeToSign)
	{
		this->_isSigned = true;
		return true;
	}
	else
	{
		this->_isSigned = false;
		return false;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
}

const char *Form::CantExecuteForm::what() const throw()
{
	return ("The form can't be executed.\n");
}

std::ostream &	operator<<( std::ostream & ostr, Form const & instance)
{
	ostr << instance.getName() << " Form has to be signed by a "
		<< instance.getSignGrade() << " grade and executed by a "
		<< instance.getExecuteGrade() << " grade, it is "
		<< ((instance.isSigned()) ? "" : "not ") << "signed";
	return ostr;
}
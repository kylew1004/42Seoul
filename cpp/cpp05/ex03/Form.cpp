/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:53:07 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:03:25 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string &name, int gradeToSign, int gradeToExecute ): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->checkGrades();
	return;
}

Form::Form( void ): _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	return;
}

Form::Form( Form const & src ): _name(src.getName()), _isSigned(src.isSigned()), _gradeToSign(src.getSignGrade()), _gradeToExecute(src.getExecuteGrade())
{
	*this = src;
	return;
}

Form::~Form( void )
{
	return;
}

Form	&Form::operator=( Form const & ref )
{
	this->_isSigned = ref._isSigned;
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

void	Form::checkExecutability( const Bureaucrat &exec ) const
{
	if (!this->_isSigned || exec.getGrade() > this->_gradeToExecute)
		throw Form::CantExecuteForm();
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
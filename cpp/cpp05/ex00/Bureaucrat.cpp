/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:26:05 by klew              #+#    #+#             */
/*   Updated: 2023/05/16 13:39:06 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name(""), _grade(150)
{
	std::cout << "Default constructor for Bureaucrat called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	checkGrade();
	std::cout << "Standard constructor for Bureaucrat called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	std::cout << "Copy constructor for Bureaucrat called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor for Bureaucrat called" << std::endl;
	return ;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & obj)
{
	this->_grade = obj._grade;
	std::cout << "Assignement operator for Bureaucrat called" << std::endl;
	return *this;
}

const std::string	&Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(int quantity)
{
	std::cout << "Grade is incremented with " << quantity << std::endl;
	this->_grade -= quantity;
	checkGrade();
}

void	Bureaucrat::decrementGrade(int quantity)
{
	std::cout << "Grade is decremented with " << quantity << std::endl;
	this->_grade += quantity;
	checkGrade();
}

void	Bureaucrat::checkGrade(void) const
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
}

std::ostream &	operator<<(std::ostream & ostr, Bureaucrat const & instance)
{
	ostr << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return ostr;
}
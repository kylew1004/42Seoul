/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:43:05 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:03:04 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Standard constructor for ShrubberyCreationForm called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "Default constructor for ShrubberyCreationForm called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ): Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "Copy constructor for ShrubberyCreationForm called" << std::endl;
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "Destructor for ShrubberyCreationForm called" << std::endl;
	return;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & ref )
{
	ref.getTarget();
	std::cout << "Assignement operator for ShrubberyCreationForm called" << std::endl;
	return *this;
}

const std::string	&ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute( const Bureaucrat &exec ) const
{
	std::ofstream	myFile;
	std::string		fileName = this->_target + "_shrubbery";

	this->checkExecutability(exec);
	myFile.open(fileName.c_str(), std::ios::out);
	myFile << "                 " << std::endl;
    myFile << "       _-_       " << std::endl;
    myFile << "    /~~   ~~\\   " << std::endl;
    myFile << " /~~         ~~\\" << std::endl;
    myFile << "{     ~         }" << std::endl;
    myFile << " \\  _-   ~ -_  /" << std::endl;
    myFile << "   ~  \\\\ //    " << std::endl;
    myFile << "       | |  ~    " << std::endl;
    myFile << "       | |     ~ " << std::endl;
    myFile << "__~___// \\\\____" << std::endl;
	myFile.close();
	std::cout << "Created the shrug in " << this->_target << "_shrubbery" << std::endl;
}
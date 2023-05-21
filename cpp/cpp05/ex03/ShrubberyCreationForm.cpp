/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:51:09 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:01:19 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("ShrubberyCreationForm", 145, 137), _target("")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ): Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & ref )
{
	ref.getTarget();
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
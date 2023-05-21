/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:38:28 by klew              #+#    #+#             */
/*   Updated: 2023/05/22 04:03:46 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:

	Bureaucrat( const std::string &name, int grade );
	Bureaucrat( const Bureaucrat &src );
	~Bureaucrat( void );

	Bureaucrat	&operator=( const Bureaucrat &obj );

	const std::string	&getName( void ) const ;
	int					getGrade( void ) const ;

	void	incrementGrade( int quantity );
	void	decrementGrade( int quantity );
	bool	executeForm( const Form &form ) const;
	bool	signForm( Form &form ) const ;

private:

	const std::string	_name;
	int					_grade;

	Bureaucrat( void );
	void	checkGrade( void ) const ;

public:

	class GradeTooHighException : public std::exception{
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char* what() const throw();
	};

};

std::ostream	&operator<<( std::ostream &ostr, const Bureaucrat &instance );

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:26:09 by klew              #+#    #+#             */
/*   Updated: 2023/05/16 13:19:06 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &rhs);

		const std::string	&getName(void) const;
		int					getGrade(void) const;

		void	incrementGrade(int quantity);
		void	decrementGrade(int quantity);

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat(void);
		void	checkGrade(void) const ;

	public:
		class GradeTooHighException : public std::exception{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &ostr, const Bureaucrat &instance);

#endif
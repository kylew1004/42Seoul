/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:27:05 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:27:09 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
 protected:
	std::string type;
 public:
	Animal(void);
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	virtual ~Animal(void);
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif

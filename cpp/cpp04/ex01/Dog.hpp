/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:22:22 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:22:26 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
 private:
	Brain *brain;
 public:
	Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog(void);
	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
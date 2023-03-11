/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:17 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:53:28 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
 public:
	Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog(void);
	void makeSound(void) const;
};

#endif
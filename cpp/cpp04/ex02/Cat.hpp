/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:25:59 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:26:04 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
 private:
	Brain *brain;
 public:
	Cat(void);
	Cat(const Cat& obj);
	Cat& operator=(const Cat& obj);
	~Cat(void);
	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
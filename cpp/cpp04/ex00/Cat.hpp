/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:05 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:53:24 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
 public:
	Cat(void);
	Cat(const Cat& obj);
	Cat& operator=(const Cat& obj);
	~Cat(void);
	void makeSound(void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:18:15 by klew              #+#    #+#             */
/*   Updated: 2023/03/12 07:53:34 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
 protected:
	std::string type;
 public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal& operator=(const WrongAnimal& obj);
	~WrongAnimal(void);
	void makeSound(void) const;
	std::string getType(void) const;
};

#endif


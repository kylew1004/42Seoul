/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:09 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 13:19:17 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:

	std::string	_name;

	public:

	Zombie 	(std::string name);
	~Zombie	(void);
	void	announce(void);
};

//newZombie
Zombie*	newZombie(std::string name);

//randomChump
void	randomChump(std::string name);
#endif
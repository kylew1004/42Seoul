/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:19 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:19 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:

	std::string _name;
	
	public:

	Zombie	( void );
	~Zombie	( void );

	bool	setName( std::string newName );
	void	announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif
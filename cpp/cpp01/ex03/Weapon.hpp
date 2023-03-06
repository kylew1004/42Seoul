/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:49 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:49 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
	std::string	type;

	public:

	const std::string&	getType();
	void				setType( const std::string& type );
	Weapon(std::string weapon);
	~Weapon(void);
};

#endif
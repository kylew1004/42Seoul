/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:53:13 by klew              #+#    #+#             */
/*   Updated: 2023/05/24 12:13:02 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
# define Serializer_HPP

# include <iostream>

typedef	struct s_data
{
	std::string	data;
}	Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& source);
		Serializer& operator=(const Serializer& source);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};


#endif
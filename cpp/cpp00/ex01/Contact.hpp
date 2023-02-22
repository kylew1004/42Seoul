/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:53:39 by klew              #+#    #+#             */
/*   Updated: 2023/02/22 17:46:50 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public:	
	void				GetInfo();
	int 				CheckContact();
	void				PrintContactInfo();
	void				CheckAndPrint(std::string info);
	const std::string&	GetContractInfo(const std::string type);
};

#endif

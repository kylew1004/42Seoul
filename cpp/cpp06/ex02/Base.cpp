/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:32:45 by klew              #+#    #+#             */
/*   Updated: 2023/05/24 11:32:54 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
}

Base* generate(void)
{
	int tmp = (rand() % 3);
	Base* ret = NULL;

	if (tmp == 0) 
		ret = new A();
	else if (tmp == 1)
		ret = new B();
	else
		ret = new C();

	return (ret);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "pointer is B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "pointer is C\n";
}

void identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "reference is A\n";
		return ;
	}
  	catch (std::exception&) {}
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "reference is B\n";
		return ;
	}
  	catch (std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "reference is C\n";
		return ;
	}
  	catch (std::exception&) {}
}
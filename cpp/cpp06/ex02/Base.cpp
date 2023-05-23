/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:32:45 by klew              #+#    #+#             */
/*   Updated: 2023/05/23 15:05:47 by klew             ###   ########.fr       */
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
		A &a = dynamic_cast<A&>(p);
		std::cout << "reference is A\n";
		static_cast<void>(a);
	}
  	catch (std::exception&) {}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "reference is B\n";
		static_cast<void>(b);
	}
  	catch (std::exception&) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "reference is C\n";
		static_cast<void>(c);
	}
  	catch (std::exception&) {}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:32:14 by klew              #+#    #+#             */
/*   Updated: 2023/05/23 15:21:22 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base * a;
	Base * b;

	srand(time(NULL));
	
	a = generate();
	b = generate();

	identify(a);
	identify(b);

	identify(*a);
	identify(*b);

	delete a;
	delete b;
	return (0);
}
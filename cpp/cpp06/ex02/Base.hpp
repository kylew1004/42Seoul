/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:33:03 by klew              #+#    #+#             */
/*   Updated: 2023/05/23 15:16:36 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <exception>

class Base 
{
  public:
	  virtual ~Base(void);
};

class A : public Base 
{
};

class B : public Base 
{
};

class C : public Base 
{
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
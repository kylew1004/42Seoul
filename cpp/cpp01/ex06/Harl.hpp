/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:03:13 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:03:14 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl( void );
    ~Harl();
    void    complain( std::string level);
    int     get_level(std::string level);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:58 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:58 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <string>
#include <fstream>

class Sed
{
    private:
    std::ifstream   _file;
    std::string     _filename;
    std::string     _s1;
    std::string     _s2;
    std::string     _new_content;

    public:
    Sed( std::string s1, std::string s2 );
    int     check_open_file( std::string filename );
    void    replace( void );
    void    output_to_file( void );
};

#endif
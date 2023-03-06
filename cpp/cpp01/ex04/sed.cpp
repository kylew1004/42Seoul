/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:56 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:56 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <iostream>

Sed::Sed(std::string s1, std::string s2): _s1(s1), _s2(s2)
{
}

int Sed::check_open_file( std::string filename)
{
    if (!this->_file.is_open())
            this->_file.close();
    if (filename == "")
        std::cout << "The filename can not be an empty string" << std::endl;
    this->_file.open(filename);
    if (!this->_file.is_open())
    {
        std::cout << "It is not possible to open the file" << std::endl;
        return (1);
    }
    if (_file.fail())
    {
        std::cout << "The filename is not correct" << std::endl;
        return (1);
    }
    this->_filename = filename;
    return (0);
}   

void    Sed::replace( void )
{
    std::string newStr;
    size_t      s1_len = _s1.length();
    if (this->_s1 == "" || this->_s2 == "")
        std::cout << "It is not possible to enter an empty string" << std::endl;
    newStr.assign(std::istreambuf_iterator<char>(this->_file), std::istreambuf_iterator<char>());
    for (size_t i = 0; i < newStr.length(); i++)
    {
        if (newStr.compare(i, s1_len, this->_s1) == 0)
        {
            newStr.erase(i, s1_len);
            newStr.insert(i, this->_s2);
        }
    }
    this->_new_content = newStr;
}

void    Sed::output_to_file( void )
{
    std::ofstream   streamNewFile;
    std::string     newFilename = this->_filename;

    newFilename += ".replace";
    streamNewFile.open(newFilename);
    streamNewFile << this->_new_content;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:02:52 by klew              #+#    #+#             */
/*   Updated: 2023/03/06 11:02:52 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "sed.hpp"

int main(int argc, char *argv[])
{
    Sed sed(argv[2], argv[3]);

    if (argc != 4)
    {
        std::cout << "You entered the wrong amount of arguments." << std::endl;
        return (1);
    }
    if (sed.check_open_file(argv[1]))
        return (1);
    sed.replace();
    sed.output_to_file();
    return (0);
}
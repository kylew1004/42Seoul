/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:20 by klew              #+#    #+#             */
/*   Updated: 2023/02/22 15:50:49 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i <= argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                argv[i][j] = std::toupper(argv[i][j]);
            }
            std::cout << argv[i];
        }
        std::cout << std::endl;
    }
}
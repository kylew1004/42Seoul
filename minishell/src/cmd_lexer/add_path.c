/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:51:33 by klew              #+#    #+#             */
/*   Updated: 2023/01/16 12:32:11 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	error_handle(char const *s)
{
	ft_putstr_fd("msh: ", 2);
	perror(s);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:00:54 by klew              #+#    #+#             */
/*   Updated: 2023/01/19 23:23:42 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dupstds(int in, int out)
{
	if (dup2(in, STDIN_FILENO) < 0 || \
		dup2(out, STDOUT_FILENO) < 0)
		error_handle("dup2");
}

int	error_handle(char const *s)
{
	ft_putstr_fd("Minishell: ", 2);
	perror(s);
	exit(EXIT_FAILURE);
}

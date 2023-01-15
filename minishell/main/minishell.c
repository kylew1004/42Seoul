/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:43:15 by klew              #+#    #+#             */
/*   Updated: 2023/01/14 14:19:25 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;

	(void)argc;
	(void)argv;
	minishell_init(&minishell, env);
	while (1)
	{
		signals();
		minishell.line = readline(PROMPT);
		if (!minishell.line)
		{
			ft_putendl_fd("exit", 2);
			exit (1);
		}
		if (ft_strlen(minishell.line))
		{
			add_history(minishell.line);
			parse(&minishell);
		}
		minishell_reset(&minishell);
		free(minishell.line);
	}
}

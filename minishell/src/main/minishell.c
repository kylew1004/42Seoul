/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:43:15 by klew              #+#    #+#             */
/*   Updated: 2023/01/16 12:02:29 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell_init(t_minishell *minishell, char **env)
{
	(void)env;
	//minishell->env = make_env(env);
	minishell->stdin_fd = dup(STDIN_FILENO);
	minishell->stdout_fd = dup(STDOUT_FILENO);
	minishell->exit_code = 0;

	minishell->sig = 0;
}

static void	minishell_reset(t_minishell *minishell)
{
	//ft_dupstds(minishell->stdin_fd, minishell->stdout_fd);
	minishell->sig = 0;
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:43:15 by klew              #+#    #+#             */
/*   Updated: 2023/01/20 05:37:19 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell_init(t_minishell *minishell, char **env)
{
	ft_bzero(minishell, sizeof(t_minishell));
	init_enviroment_vars(&minishell->vars, env);
	minishell->env = make_environment(minishell->vars);
	minishell->stdin_fd = dup(STDIN_FILENO);
	minishell->stdout_fd = dup(STDOUT_FILENO);
	minishell->redir[IN] = STDIN_FILENO;
	minishell->redir[OUT] = STDOUT_FILENO;
	minishell->exit_code = 0;
	minishell->sig = 0;
}

static void	minishell_reset(t_minishell *minishell)
{
	ft_dupstds(minishell->stdin_fd, minishell->stdout_fd);
	minishell->sig = 0;
}

static void	_free_minishell(t_minishell *minishell)
{
	ft_lstclear(&minishell->vars, free_variable);
	free_ptrarray(minishell->env);
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
			exit (0);
		}
		if (ft_strlen(minishell.line))
		{
			add_history(minishell.line);
			parse(&minishell);
		}
		minishell_reset(&minishell);
		free(minishell.line);
	}
	_free_minishell(&minishell);
}

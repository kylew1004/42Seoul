/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:41 by klew              #+#    #+#             */
/*   Updated: 2023/01/21 03:39:05 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_close_redir_files(t_minishell *minishell)
{
	if (minishell->redir[IN] != STDIN_FILENO)
		close(minishell->redir[IN]);
	if (minishell->redir[OUT] != STDOUT_FILENO)
		close(minishell->redir[OUT]);
	minishell->redir[IN] = STDIN_FILENO;
	minishell->redir[OUT] = STDOUT_FILENO;
}

int	handle_cmd(char *cmd, t_minishell *minishell, int piped)
{
	char	**cmd_words;
	int		status;

	if (redirect_cmd(cmd, minishell) || minishell->sig == SIGINT)
	{
		free(cmd);
		return (1);
	}
	if (minishell->sig == EOF)
	{
		ft_putstr_fd("EOF", 2);
		minishell->sig = EOF;
	}
	cmd = remove_redirections(cmd);
	if (!cmd)
		return (1);
	cmd = expansions(cmd, minishell);
	cmd_words = ft_split_cmd(cmd, ' ');
	status = control_execute(cmd_words, minishell, piped);
	_close_redir_files(minishell);
	free(cmd);
	free_ptrarray(cmd_words);
	return (status);
}

int	ft_ptrarlen(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	return (i);
}

void	parse(t_minishell *minishell)
{
	char	*dup_cmd;

	if (!check_tokens(minishell->line, minishell))
		return ;
	minishell->cmds = ft_split_shell(minishell->line, '|');
	minishell->pipex.am_cmds = ft_ptrarlen(minishell->cmds);
	if (minishell->pipex.am_cmds > 1)
		minishell->exit_code = ft_pipex(minishell->cmds, \
		minishell->pipex, *minishell);
	else
	{
		dup_cmd = ft_strdup(minishell->cmds[0]);
		if (!dup_cmd)
		{
			free_ptrarray(minishell->cmds);
			return ;
		}
		minishell->exit_code = handle_cmd(dup_cmd, minishell, 0);
	}
	free_ptrarray(minishell->cmds);
	return ;
}

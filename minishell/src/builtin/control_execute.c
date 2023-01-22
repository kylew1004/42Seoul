/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:19:21 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/20 20:54:30 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_execute(char *cmd_name, char **cmd_words, t_minishell *minishell)
{
	if (access(cmd_name, F_OK | X_OK) == NO_ERROR)
		if (execve(cmd_name, cmd_words, minishell->env) == -1)
			exit(0);
	if (access(cmd_name, F_OK) == NO_ERROR)
		exit(126);
}

static char	*_valid_cmd_name(char **cmd_words, t_minishell *minishell)
{
	char	**paths;
	char	*tmp;
	char	*cmd;
	int		i;

	paths = get_paths(minishell->env);
	if (!paths)
		return (NULL);
	i = 0;
	cmd = ft_strdup("");
	while (paths[i])
	{
		tmp = cmd;
		cmd = ft_strjoin(paths[i], "/");
		free(tmp);
		cmd = ft_strjoin(cmd, cmd_words[0]);
		if (access(cmd, F_OK | X_OK) == NO_ERROR)
		{
			free_ptrarray(paths);
			return (cmd);
		}
		++i;
	}
	free_ptrarray(paths);
	return (NULL);
}

static void	_non_fork_execute(char **cmd_words, t_minishell *minishell)
{
	char	*cmd;

	if (!cmd_words[0])
	{
		write(STDERR_FILENO, "Minishell: command not found\n", 30);
		exit(127);
	}
	_execute(cmd_words[0], cmd_words, minishell);
	cmd = _valid_cmd_name(cmd_words, minishell);
	if (!cmd_words[0][0] || !cmd)
	{
		write(STDERR_FILENO, "Minishell: command not found\n", 30);
		exit(127);
	}
	_execute(cmd, cmd_words, minishell);
}

static int	_fork_execute(char **cmd_words, t_minishell *minishell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		error_handle("Fork");
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		_non_fork_execute(cmd_words, minishell);
	}
	signal(SIGINT, SIG_IGN);
	wait(&status);
	return (WEXITSTATUS(status));
}

int	control_execute(char **cmd_words, t_minishell *minishell, int piped)
{
	int	status;

	if (is_builtin_cmd(cmd_words[0]))
		return (search_builtin(cmd_words, minishell));
	status = 0;
	if (piped)
		_non_fork_execute(cmd_words, minishell);
	else
		status = _fork_execute(cmd_words, minishell);
	return (status);
}

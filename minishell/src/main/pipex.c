/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:30:32 by klew              #+#    #+#             */
/*   Updated: 2023/01/21 18:30:43 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_exec(char *cmd, t_pipex pipex, t_minishell minishell)
{
	if (!pipex.iter)
		ft_dupstds(STDIN_FILENO, pipex.new_pipe[1]);
	else if (pipex.iter == pipex.am_cmds - 1)
		ft_dupstds(pipex.last_pipe, STDOUT_FILENO);
	else
		ft_dupstds(pipex.last_pipe, pipex.new_pipe[1]);
	if (pipex.iter != 0)
		close(pipex.last_pipe);
	close(pipex.new_pipe[0]);
	close(pipex.new_pipe[1]);
	handle_cmd(cmd, &minishell, 1);
	exit(1);
}

pid_t	fork_child(char *cmd, t_pipex pipex, t_minishell minishell)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		error_handle("Fork");
	if (child == 0)
		child_exec(cmd, pipex, minishell);
	if (pipex.iter > 0)
		close(pipex.last_pipe);
	ft_dupstds(minishell.stdin_fd, minishell.stdout_fd);
	return (child);
}

int	ft_pipex(char **cmds, t_pipex pipex, t_minishell minishell)
{
	pid_t	*childs;
	int		status;

	childs = ft_calloc(pipex.am_cmds, sizeof(pid_t));
	if (!childs)
		error_handle("Malloc");
	pipex.iter = 0;
	while (pipex.iter < pipex.am_cmds)
	{
		if (pipe(pipex.new_pipe) < 0)
			error_handle("Pipe");
		sig_default();
		childs[pipex.iter] = fork_child(cmds[pipex.iter], pipex, minishell);
		sig_ignore();
		waitpid(childs[pipex.iter], &status, 0);
		pipex.last_pipe = pipex.new_pipe[0];
		close(pipex.new_pipe[1]);
		pipex.iter++;
	}
	free(childs);
	close(pipex.new_pipe[0]);
	if (status == SIGINT)
		return (130);
	return (WEXITSTATUS(status));
}

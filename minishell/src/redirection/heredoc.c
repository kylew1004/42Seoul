/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:38:26 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/21 03:38:05 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	_count_not_quote_char(char *line)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] != '\'' && line[i] != '\"')
			++len;
		++i;
	}
	return (len);
}

static char	*_removed_quote(char *line)
{
	int		i;
	char	*removed;
	size_t	len;

	len = _count_not_quote_char(line);
	removed = (char *)malloc(sizeof(char) * (len + 1));
	if (!removed)
		return (NULL);
	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] != '\'' && line[i] != '\"')
		{
			removed[len] = line[i];
			++len;
		}
		++i;
	}
	free(line);
	removed[len] = '\0';
	return (removed);
}

static int	_process_heredoc(const char *delim, int pw, t_minishell *minishell)
{
	char	*line;
	char	*expanded;

	while (TRUE)
	{
		line = readline(">");
		if (!line || !ft_strcmp(line, delim))
			break ;
		expanded = expansions(line, minishell);
		line = _removed_quote(expanded);
		ft_putendl_fd(line, pw);
		free(line);
	}
	exit(0);
}

int	heredoc(const char *delim, t_minishell *minishell)
{
	int		heredoc_fd[2];
	pid_t	pid;
	int		status;

	if (pipe(heredoc_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		error_handle("Fork");
	if (pid == 0)
	{
		signal(SIGINT, sigint_handler_heredoc);
		ft_dupstds(minishell->stdin_fd, minishell->stdout_fd);
		_process_heredoc(delim, heredoc_fd[1], minishell);
	}
	signal(SIGINT, SIG_IGN);
	wait(&status);
	if (WEXITSTATUS(status))
	{
		close(heredoc_fd[0]);
		close(heredoc_fd[1]);
		return (-1);
	}
	close(heredoc_fd[1]);
	return (heredoc_fd[0]);
}

int	run_heredoc(char **splitted, t_minishell *minishell)
{
	int		i;
	char	**tokens;

	i = 0;
	while (splitted[i])
	{
		tokens = tokenize_redirect(splitted[i]);
		if (!tokens)
			return (ERROR);
		if (!ft_strcmp(tokens[0], "<<"))
			minishell->last_heredoc = heredoc(tokens[1], minishell);
		free_ptrarray(tokens);
		++i;
	}
	return (NO_ERROR);
}

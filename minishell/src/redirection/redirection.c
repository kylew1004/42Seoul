/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:11:21 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/20 18:26:42 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "errno.h"

static int	_redirect_input(int *stdin_fd, const char *path)
{
	*stdin_fd = open(path, O_RDWR);
	if (*stdin_fd == -1)
	{
		write(STDERR_FILENO, "Minishell: Invalid filename.\n", 30);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	_redirect_output(int *stdout_fd, const char *path)
{
	*stdout_fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*stdout_fd == -1)
		return (ERROR);
	return (NO_ERROR);
}

static int	_redirect_output_append(int *stdout_fd, const char *path)
{
	*stdout_fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (*stdout_fd == -1)
		return (ERROR);
	return (NO_ERROR);
}

static int	_parse_redirect(char **redirect_str, t_minishell *minishell)
{
	int		err;

	err = ERROR;
	if (!ft_strncmp(redirect_str[0], "<<", 2))
	{
		minishell->redir[IN] = minishell->last_heredoc;
		if (minishell->redir[IN] == -1)
			return (ERROR);
		err = NO_ERROR;
	}
	else if (!ft_strncmp(redirect_str[0], ">>", 2))
		err = _redirect_output_append(&minishell->redir[OUT], redirect_str[1]);
	else if (!ft_strncmp(redirect_str[0], "<", 1))
		err = _redirect_input(&minishell->redir[IN], redirect_str[1]);
	else if (!ft_strncmp(redirect_str[0], ">", 1))
		err = _redirect_output(&minishell->redir[OUT], redirect_str[1]);
	else
		return (ERROR);
	return (err);
}

int	redirection(char **redirect_str, t_minishell *minishell)
{
	int		err;

	err = _parse_redirect(redirect_str, minishell);
	if (err)
		return (ERROR);
	if (minishell->redir[IN] != STDIN_FILENO)
	{
		err = dup2(minishell->redir[IN], STDIN_FILENO);
		if (err == -1)
			return (ERROR);
	}
	if (minishell->redir[OUT] != STDOUT_FILENO)
	{
		err = dup2(minishell->redir[OUT], STDOUT_FILENO);
		if (err == -1)
			return (ERROR);
	}
	return (NO_ERROR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:02:07 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/21 03:38:54 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**_get_tokens(const char *redir_op, const char *redir_str)
{
	char	**redir_token;
	int		i;
	int		start;

	redir_token = (char **)malloc(sizeof(char *) * 3);
	if (!redir_token)
		return (NULL);
	redir_token[0] = ft_strdup(redir_op);
	i = 0;
	start = -1;
	while (redir_str[i])
	{
		if (start == -1 && redir_str[i] != ' ')
			start = i;
		++i;
	}
	redir_token[1] = ft_strdup(redir_str + start);
	redir_token[2] = NULL;
	return (redir_token);
}

char	**tokenize_redirect(const char *redir_str)
{
	if (!redir_str)
		return (NULL);
	if (redir_str[1] == '<')
		return (_get_tokens("<<", redir_str + 2));
	if (redir_str[1] == '>')
		return (_get_tokens(">>", redir_str + 2));
	if (redir_str[0] == '<')
		return (_get_tokens("<", redir_str + 1));
	if (redir_str[0] == '>')
		return (_get_tokens(">", redir_str + 1));
	return (NULL);
}

int	control_redirect(const char *redir_str, t_minishell *minishell)
{
	int		err;
	char	**tokens;

	minishell->redir[IN] = STDIN_FILENO;
	minishell->redir[OUT] = STDOUT_FILENO;
	tokens = tokenize_redirect(redir_str);
	if (!tokens)
		return (ERROR);
	err = redirection(tokens, minishell);
	free_ptrarray(tokens);
	return (err);
}

static int	_run_redirect(char **splitted, t_minishell *minishell)
{
	int		i;

	i = 0;
	while (splitted[i])
	{
		if (control_redirect(splitted[i], minishell))
			return (ERROR);
		++i;
	}
	return (NO_ERROR);
}

int	redirect_cmd(char *cmd, t_minishell *minishell)
{
	int		err;
	char	**splitted;

	err = 0;
	splitted = get_splitted_redirect(cmd);
	if (!splitted)
		return (ERROR);
	err = run_heredoc(splitted, minishell);
	if (err)
	{
		free_ptrarray(splitted);
		return (ERROR);
	}
	err = _run_redirect(splitted, minishell);
	if (err)
	{
		free_ptrarray(splitted);
		return (ERROR);
	}
	free_ptrarray(splitted);
	return (NO_ERROR);
}

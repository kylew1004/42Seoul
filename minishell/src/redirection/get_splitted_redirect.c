/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_splitted_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:59:06 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/20 21:33:24 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_get_redirect_num(char *redir_cmd)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (redir_cmd[i])
	{
		if (redir_cmd[i] == '\'' || redir_cmd[i] == '\"' )
			skip_quote2(&redir_cmd[i], &i);
		if (redir_cmd[i] == '<' || redir_cmd[i] == '>')
			++num;
		++i;
		if ((redir_cmd[i - 1] == '<' || redir_cmd[i - 1] == '>') \
			&& (redir_cmd[i] == '<' || redir_cmd[i] == '>'))
			++i;
	}
	return (num);
}

static void	_skip_redirection(char *redir_cmd, int *i)
{
	while (redir_cmd[*i] == ' ')
		++(*i);
	while (redir_cmd[*i] && redir_cmd[*i] != ' ' \
		&& redir_cmd[*i] != '<' && redir_cmd[*i] != '>')
		++(*i);
}

static void	_fill_split_cmd(char ***splitted, char *redir_cmd)
{
	int	it[2];
	int	start;

	ft_memset(it, 0, sizeof(int) * 2);
	start = -1;
	while (redir_cmd[it[0]])
	{
		if (redir_cmd[it[0]] == '\'' || redir_cmd[it[0]] == '\"' )
			skip_quote2(&redir_cmd[it[0]], &it[0]);
		if (redir_cmd[it[0]] == '<' || redir_cmd[it[0]] == '>')
			start = it[0];
		++it[0];
		if ((redir_cmd[it[0] - 1] == '<' || redir_cmd[it[0] - 1] == '>') \
			&& (redir_cmd[it[0]] == '<' || redir_cmd[it[0]] == '>'))
			++it[0];
		if (start != -1)
		{
			_skip_redirection(redir_cmd, &it[0]);
			(*splitted)[it[1]] = ft_strndup(redir_cmd + start, it[0] - start);
			if (!(*splitted)[it[1]])
				free_ptrarray(*splitted);
			++it[1];
			start = -1;
		}
	}
}

char	**get_splitted_redirect(char *redir_cmd)
{
	char	**splitted;
	int		redir_num;

	redir_num = _get_redirect_num(redir_cmd);
	splitted = (char **)ft_calloc((redir_num + 1), sizeof(char *));
	if (!splitted)
		return (NULL);
	_fill_split_cmd(&splitted, redir_cmd);
	return (splitted);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:21:30 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/20 21:30:12 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_remove(char *removed, int *i)
{
	while (removed[*i] == ' ')
			++(*i);
	while (removed[*i] && removed[*i] != ' ')
	{
		removed[*i] = ' ';
		++(*i);
	}
}

static void	_remove_loop(char *removed)
{
	int		i;
	int		rm_flag;

	i = 0;
	rm_flag = 0;
	while (removed[i])
	{
		if (removed[i] == '\'' || removed[i] == '\"' )
			skip_quote2(&removed[i], &i);
		while (removed[i] == '<' || removed[i] == '>')
		{
			removed[i] = ' ';
			rm_flag = 1;
			++i;
		}
		if (rm_flag)
			_remove(removed, &i);
		if (!removed[i])
			break ;
		rm_flag = 0;
		++i;
	}
}

char	*remove_redirections(char *cmd)
{
	char	*removed;

	removed = ft_strdup(cmd);
	if (!removed)
		return (NULL);
	_remove_loop(removed);
	free(cmd);
	return (removed);
}

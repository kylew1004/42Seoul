/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:25 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/20 20:31:06 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_cmd(const char *cmd)
{
	if (!cmd)
		return (FALSE);
	if (!ft_strcmp("cd", cmd) || !ft_strcmp("echo", cmd) \
		|| !ft_strcmp("env", cmd) || !ft_strcmp("exit", cmd) \
		|| !ft_strcmp("export", cmd) || !ft_strcmp("pwd", cmd) \
		|| !ft_strcmp("unset", cmd))
		return (TRUE);
	return (FALSE);
}

char	**get_paths(char **envs)
{
	char	**paths;
	int		i;

	i = 0;
	while (envs[i])
	{
		if (!ft_strncmp(envs[i], "PATH=", 5))
			break ;
		++i;
	}
	if (!envs[i])
		return (NULL);
	paths = ft_split(envs[i] + 5, ':');
	return (paths);
}

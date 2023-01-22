/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:26:52 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/18 11:19:10 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_enviroment_vars(t_var_list **env, char *envp[])
{
	int			i;
	t_variable	*var;
	t_list		*new_node;

	i = 0;
	while (envp[i])
	{
		var = parse_variable(envp[i], ENV);
		if (!var)
			return (ERROR);
		new_node = ft_lstnew(var);
		if (!new_node)
			return (ERROR);
		ft_lstadd_back(env, new_node);
		++i;
	}
	return (NO_ERROR);
}

t_variable	*find_variable(t_var_list *vars, const char *key)
{
	t_variable	*found;
	t_var_list	*cur;
	size_t		len;

	if (!vars || !key)
		return (NULL);
	len = ft_strlen(key);
	cur = vars;
	while (cur)
	{
		found = (t_variable *)cur->content;
		if (len < ft_strlen(found->key))
			len = ft_strlen(found->key);
		if (!ft_strncmp(found->key, key, len))
			return (found);
		cur = cur->next;
	}
	return (NULL);
}

static size_t	_get_env_num(t_var_list *vars)
{
	t_var_list	*cur;
	size_t		num;

	cur = vars;
	num = 0;
	while (cur)
	{
		if (((t_variable *)cur->content)->type == ENV)
			++num;
		cur = cur->next;
	}
	return (num);
}

static char	*_get_joinned_var_str(char *key, char *value)
{
	char	*joinned;
	size_t	key_len;
	size_t	value_len;

	key_len = ft_strlen(key);
	value_len = ft_strlen(value);
	joinned = (char *)malloc(sizeof(char) * (key_len + value_len + 2));
	if (!joinned)
		return (NULL);
	ft_strlcpy(joinned, key, key_len + 1);
	ft_strlcpy(joinned + key_len, "=", 2);
	ft_strlcpy(joinned + key_len + 1, value, value_len + 1);
	return (joinned);
}

char	**make_environment(t_var_list *vars)
{
	t_var_list	*cur;
	t_variable	*var;
	char		**envp;
	int			i;

	envp = (char **)malloc(sizeof(char *) * (_get_env_num(vars) + 1));
	if (!envp)
		return (NULL);
	ft_bzero(envp, sizeof(char *) * (_get_env_num(vars) + 1));
	cur = vars;
	i = 0;
	while (cur)
	{
		var = (t_variable *)cur->content;
		if (var->type == ENV)
		{
			envp[i] = _get_joinned_var_str(var->key, var->value);
			++i;
		}
		cur = cur->next;
	}
	return (envp);
}

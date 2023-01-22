/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:46:28 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/16 00:37:40 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable	*parse_variable(const char *var_str, t_var_type type)
{
	t_variable	*var;
	char		*val_str;
	size_t		len;

	if (!var_str)
		return (NULL);
	var = (t_variable *)malloc(sizeof(t_variable));
	if (!var)
		return (NULL);
	ft_bzero(var, sizeof(t_variable));
	len = ft_strlen(var_str);
	val_str = ft_strchr(var_str, '=');
	if (val_str)
	{
		var->key = ft_strndup(var_str, val_str - var_str);
		var->value = ft_strndup(val_str + 1, len - (val_str - var_str) - 1);
		var->type = type;
		return (var);
	}
	var->key = ft_strdup(var_str);
	var->value = ft_strdup("");
	var->type = EPT;
	return (var);
}

void	free_variable(void *var)
{
	free(((t_variable *)var)->key);
	free(((t_variable *)var)->value);
	free(var);
}

int	check_valid_identifier(const char *key)
{
	int	i;

	if (!key)
		return (ERROR);
	i = 0;
	if (!ft_isalpha(key[i]) && key[i++] != '_')
		return (ERROR);
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (ERROR);
		++i;
	}
	return (NO_ERROR);
}

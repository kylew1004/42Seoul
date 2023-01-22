/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:05:31 by klew              #+#    #+#             */
/*   Updated: 2023/01/20 20:16:16 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*skip_var_name(char *s)
{
	if (ft_isdigit(*s))
		s++;
	else
	{
		while ((ft_isalnum(*s) || *s == '_') && *s)
			s++;
		if (*s == '?' && *(s - 1) == '$')
			s++;
	}
	return (s);
}

int	len_array(char	**a)
{
	unsigned int	total;
	int				i;

	total = 0;
	i = 0;
	while (a[i])
	{
		total += ft_strlen(a[i]);
		i++;
	}
	return (total);
}

char	*conv_var(char *s, t_minishell *minishell)
{
	char	*var_name;
	char	*var;

	if (!ft_strncmp(s + 1, "?", 1) || ft_isdigit(*(s + 1)))
		var_name = s + 1;
	else if (!*(s + 1))
		var_name = s;
	else
		var_name = ft_strjoin(s + 1, "=");
	if (!var_name)
		error_handle("Malloc");
	var = ft_getenv(var_name, minishell);
	if (var_name != s + 1 && var_name != s)
		free(var_name);
	free(s);
	return (var);
}

int	conv_vars(char **vars, t_minishell *minishell)
{
	int	var_len;
	int	i;

	var_len = len_array(vars);
	i = 0;
	while (vars[i])
	{
		vars[i] = conv_var(vars[i], minishell);
		i++;
	}
	var_len = len_array(vars) - var_len;
	return (var_len);
}

void	sub_vars(char *new_s, char *s, char **vars)
{
	char	*freeptr;

	while (*vars)
	{
		ft_memcpy(new_s, s, ft_strchr_var(s, '$') - s);
		new_s += ft_strchr_var(s, '$') - s;
		s = ft_strchr_var(s, '$') + 1;
		s = skip_var_name(s);
		freeptr = *vars;
		while (**vars)
		{
			*new_s = **vars;
			new_s++;
			(*vars)++;
		}
		free(freeptr);
		vars++;
	}
	if (*s)
		ft_memcpy(new_s, s, ft_strlen(s));
	new_s = 0;
}

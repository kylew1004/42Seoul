/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:32:37 by klew              #+#    #+#             */
/*   Updated: 2023/01/19 14:04:11 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *var, t_minishell *minishell)
{
	int		i;
	char	*pointer;
	size_t	var_len;

	i = 0;
	if (!ft_strncmp(var, "?", 1))
		return (ft_itoa(minishell->exit_code));
	if (*var == '$')
		return (ft_strdup_shell("$"));
	var_len = ft_strlen(var);
	pointer = NULL;
	while (!pointer)
	{
		if (!minishell->env[i])
			break ;
		pointer = (ft_strnstr(minishell->env[i], var, var_len));
		i++;
	}
	if (!pointer)
		return (ft_strdup_shell("\0"));
	pointer = ft_substr(pointer, var_len, ft_strlen(pointer + var_len));
	return (pointer);
}

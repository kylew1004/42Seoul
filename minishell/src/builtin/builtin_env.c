/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:10:06 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/17 11:21:16 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(char **argv, t_var_list *vars)
{
	t_var_list	*cur;
	t_variable	*data;

	if (argv[1])
	{
		write(STDERR_FILENO, \
			"Minishell: env: must not have arguments or options\n", 52);
		return (EXIT_FAILURE);
	}
	cur = vars;
	while (cur)
	{
		data = ((t_variable *)cur->content);
		if (data->type == ENV)
			printf("%s=%s\n", data->key, data->value);
		cur = cur->next;
	}
	return (EXIT_SUCCESS);
}

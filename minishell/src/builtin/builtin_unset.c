/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:35:20 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/17 11:21:16 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_process_args(t_var_list *vars, const char *key)
{
	t_var_list	*deleted;
	t_var_list	*prev;
	t_variable	*var;
	size_t		len;

	deleted = vars;
	prev = NULL;
	len = ft_strlen(key);
	while (deleted)
	{
		var = (t_variable *)deleted->content;
		if (len < ft_strlen(var->key))
			len = ft_strlen(var->key);
		if (!ft_strncmp(var->key, key, len))
		{
			if (!prev)
				vars = deleted->next;
			prev->next = deleted->next;
			ft_lstdelone(deleted, free_variable);
		}
		prev = deleted;
		deleted = deleted->next;
	}
}

int	builtin_unset(char **argv, t_var_list *vars)
{
	int			exit_status;
	int			err;
	int			i;

	i = 1;
	exit_status = EXIT_SUCCESS;
	while (argv[i])
	{
		err = check_valid_identifier(argv[i]);
		exit_status |= err;
		if (err)
		{
			write(STDERR_FILENO, \
			"Minishell: unset: not a valid identifier\n", 42);
			++i;
			continue ;
		}
		_process_args(vars, argv[i]);
		++i;
	}
	return (exit_status);
}

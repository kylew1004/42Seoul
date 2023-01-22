/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:14 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/20 05:09:29 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_variable	*_get_var_arr(t_var_list *vars, int size)
{
	t_variable	*var_arr;
	t_var_list	*cur;
	int			i;

	if (!vars | !size)
		return (NULL);
	var_arr = (t_variable *)malloc(sizeof(t_variable) * size);
	i = 0;
	cur = vars;
	while (cur)
	{
		var_arr[i] = *(t_variable *)cur->content;
		++i;
		cur = cur->next;
	}
	return (var_arr);
}

static int	_print_declare_script(t_var_list *vars)
{
	t_variable	*var_arr;
	int			i;
	int			size;

	size = ft_lstsize(vars);
	var_arr = _get_var_arr(vars, size);
	if (!var_arr)
		return (ERROR);
	sort_alphabet_ascending(var_arr, 0, size - 1);
	i = 0;
	while (i < size)
	{
		if (var_arr[i].type == ENV)
			printf("declare -x %s=\"%s\"\n", var_arr[i].key, var_arr[i].value);
		else if (var_arr[i].type == EPT)
			printf("declare -x %s\n", var_arr[i].key);
		++i;
	}	
	free(var_arr);
	return (NO_ERROR);
}

static t_variable	*_check_and_create_variable(const char *arg)
{
	t_variable	*var;
	int			err;

	var = parse_variable(arg, ENV);
	if (!var)
		return (NULL);
	err = check_valid_identifier(var->key);
	if (err)
	{
		free_variable(var);
		write(STDERR_FILENO, \
			"Minishell: export: not a valid identifier\n", 43);
		return (NULL);
	}
	return (var);
}

static int	_process_args(t_var_list *vars, const char *arg)
{
	t_variable	*var;
	t_variable	*found;
	t_var_list	*new_node;

	var = _check_and_create_variable(arg);
	if (!var)
		return (ERROR);
	found = find_variable(vars, var->key);
	if (!found)
	{
		new_node = ft_lstnew(var);
		if (!new_node)
			return (ERROR);
		ft_lstadd_back(&vars, new_node);
		return (NO_ERROR);
	}
	if (var->type != EPT)
	{
		free(found->value);
		found->value = ft_strdup(var->value);
		found->type = ENV;
	}
	free_variable(var);
	return (NO_ERROR);
}

int	builtin_export(char **argv, t_var_list *vars)
{
	int			err;
	int			i;

	err = 0;
	if (!argv[1])
	{
		err = _print_declare_script(vars);
		if (err)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	i = 1;
	while (argv[i])
	{
		err = err | _process_args(vars, argv[i]);
		++i;
	}
	if (err)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

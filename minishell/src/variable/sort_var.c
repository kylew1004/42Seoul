/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:41:03 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/15 20:18:48 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_compare_str(char *str1, char *str2)
{
	size_t	str_len1;
	size_t	str_len2;
	int		result;

	str_len1 = ft_strlen(str1);
	str_len2 = ft_strlen(str2);
	if (str_len1 <= str_len2)
		result = ft_strncmp(str1, str2, str_len2);
	else
		result = ft_strncmp(str1, str2, str_len1);
	return (result);
}

static void	_swap(t_variable *var1, t_variable *var2)
{
	t_variable	temp;

	temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

static int	_partition(t_variable *var_arr, int left, int right)
{
	int			l;
	int			r;
	t_variable	pivot;

	l = left;
	r = right;
	pivot = var_arr[(left + right) / 2];
	_swap(&var_arr[(left + right) / 2], &var_arr[left]);
	while (l < r)
	{
		while (l <= right && _compare_str(var_arr[l].key, pivot.key) <= 0)
			++l;
		while (left < r && _compare_str(pivot.key, var_arr[r].key) <= 0)
			--r;
		if (l < r)
			_swap(&var_arr[l], &var_arr[r]);
	}
	_swap(&var_arr[left], &var_arr[r]);
	return (r);
}

int	sort_alphabet_ascending(t_variable *var_arr, int left, int right)
{
	int	pivot_pos;

	if (left < right)
	{
		pivot_pos = _partition(var_arr, left, right);
		sort_alphabet_ascending(var_arr, left, pivot_pos - 1);
		sort_alphabet_ascending(var_arr, pivot_pos + 1, right);
	}
	return (0);
}

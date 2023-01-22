/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:21:17 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/17 11:21:16 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_is_in_numeric_range(const char *str)
{
	unsigned long long	result;
	size_t				i;
	int					is_neg;

	result = 0;
	if (!str)
		return (result);
	i = 0;
	is_neg = 0;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	if (!is_neg && LLONG_MAX < result)
		return (FALSE);
	if (is_neg && (unsigned long long)LLONG_MAX + 1 < result)
		return (FALSE);
	return (TRUE);
}

static int	_is_numeric_str(const char *str)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (FALSE);
	len = ft_strlen(str);
	if (len > 20)
		return (FALSE);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		++i;
	}
	if (!_is_in_numeric_range(str))
		return (FALSE);
	return (TRUE);
}

static long long	_ft_atoll(const char *str)
{
	unsigned long long	result;
	size_t				i;
	int					sign;

	result = 0;
	if (!str)
		return (result);
	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	return ((long long)(result * sign));
}

int	builtin_exit(char **argv)
{
	int	exit_status;

	write(STDOUT_FILENO, "exit\n", 6);
	if (argv[1] && !_is_numeric_str(argv[1]))
	{
		write(STDERR_FILENO, "Minishell: exit: numeric argument required\n", 44);
		exit(EXIT_STATUS_BUILTIN_EXIT_ARG_NON_NUMERIC);
	}
	if (argv[1] && argv[2])
	{
		write(STDERR_FILENO, "Minishell: exit: too many arguments\n", 37);
		return (EXIT_FAILURE);
	}
	exit_status = 0;
	if (argv[1])
		exit_status = (int)_ft_atoll(argv[1]);
	exit(exit_status);
}

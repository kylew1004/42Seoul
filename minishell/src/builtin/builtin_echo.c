/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:59:16 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/19 23:46:21 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_ft_strarrjoin(char **strarr, const char *conn_str)
{
	size_t	word_cnt;
	size_t	i;
	char	*joinned;
	char	*temp;

	word_cnt = 0;
	while (strarr[word_cnt])
		++word_cnt;
	i = 0;
	joinned = ft_strdup("");
	while (joinned && i < word_cnt)
	{
		temp = joinned;
		joinned = ft_strjoin(joinned, strarr[i]);
		free(temp);
		if (!joinned)
			break ;
		temp = joinned;
		joinned = ft_strjoin(joinned, conn_str);
		free(temp);
		++i;
	}
	return (joinned);
}

int	builtin_echo(char **argv)
{
	int		i;
	int		no_lf;
	char	*print_str;

	i = 1;
	no_lf = 0;
	while (argv[i] && !ft_strncmp(argv[i], "-n", 2))
	{
		no_lf = 1;
		++i;
	}
	if (!argv[i] && !no_lf)
		write(STDOUT_FILENO, "\n", 1);
	print_str = _ft_strarrjoin(&argv[i], " ");
	if (!print_str)
		return (EXIT_FAILURE);
	if (no_lf)
		print_str[ft_strlen(print_str) - 1] = '\0';
	else
		print_str[ft_strlen(print_str) - 1] = '\n';
	write(STDOUT_FILENO, print_str, ft_strlen(print_str));
	free(print_str);
	return (EXIT_SUCCESS);
}

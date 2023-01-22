/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:57:01 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/10 17:39:50 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(void)
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
		return (EXIT_FAILURE);
	write(STDOUT_FILENO, cur_dir, ft_strlen(cur_dir));
	write(STDOUT_FILENO, "\n", 1);
	free(cur_dir);
	return (EXIT_SUCCESS);
}

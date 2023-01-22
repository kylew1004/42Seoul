/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:01:11 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/19 17:34:44 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_builtin(char **cmd_words, t_minishell *minishell)
{
	int	exit_status;

	exit_status = 0;
	if (!ft_strcmp(cmd_words[0], "cd"))
		exit_status = builtin_cd(cmd_words, minishell->vars);
	else if (!ft_strcmp(cmd_words[0], "echo"))
		exit_status = builtin_echo(cmd_words);
	else if (!ft_strcmp(cmd_words[0], "env"))
		exit_status = builtin_env(cmd_words, minishell->vars);
	else if (!ft_strcmp(cmd_words[0], "exit"))
		exit_status = builtin_exit(cmd_words);
	else if (!ft_strcmp(cmd_words[0], "export"))
		exit_status = builtin_export(cmd_words, minishell->vars);
	else if (!ft_strcmp(cmd_words[0], "pwd"))
		exit_status = builtin_pwd();
	else if (!ft_strcmp(cmd_words[0], "unset"))
		exit_status = builtin_unset(cmd_words, minishell->vars);
	free_ptrarray(minishell->env);
	minishell->env = make_environment(minishell->vars);
	return (exit_status);
}

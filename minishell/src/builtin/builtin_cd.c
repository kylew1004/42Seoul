/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:45:28 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/19 17:33:43 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_go_root_dir(void)
{
	int		err;
	char	*cur_dir;

	err = 0;
	cur_dir = getcwd(NULL, 0);
	while (!err && ft_strncmp(cur_dir, "/", 2))
	{
		err = chdir("../");
		free(cur_dir);
		cur_dir = getcwd(NULL, 0);
	}
	free(cur_dir);
	return (err);
}

static int	_change_absolute_address(char *abs_path)
{
	char	*cur_dir;
	int		err;

	cur_dir = getcwd(NULL, 0);
	err = _go_root_dir();
	if (err)
	{
		chdir(&cur_dir[1]);
		free(cur_dir);
		return (err);
	}
	err = chdir(&abs_path[1]);
	if (err)
	{
		free(cur_dir);
		return (err);
	}
	free(cur_dir);
	return (err);
}

static int	_check_exist_dir(const char *filename)
{
	DIR	*dir;

	dir = opendir(filename);
	if (!dir)
	{
		write(STDERR_FILENO, \
		"Minishell: cd: argument error\n", 31);
		return (EXIT_FAILURE);
	}
	closedir(dir);
	return (EXIT_SUCCESS);
}

static void	_modify_related_env(t_var_list *vars)
{
	t_var_list	*cur;
	t_variable	*old_pwd;
	t_variable	*pwd;
	char		*cur_dir;

	cur_dir = getcwd(NULL, 0);
	cur = vars;
	while (cur)
	{
		if (!ft_strcmp(((t_variable *)cur->content)->key, "OLDPWD"))
			old_pwd = ((t_variable *)cur->content);
		if (!ft_strcmp(((t_variable *)cur->content)->key, "PWD"))
			pwd = ((t_variable *)cur->content);
		cur = cur->next;
	}
	free(old_pwd->value);
	old_pwd->value = pwd->value;
	pwd->value = cur_dir;
}

int	builtin_cd(char **argv, t_var_list *vars)
{
	int		err;

	if (!argv[1])
	{
		write(STDERR_FILENO, "Minishell: cd: needs at least one argument\n", 44);
		return (EXIT_FAILURE);
	}
	err = _check_exist_dir(argv[1]);
	if (err)
		return (EXIT_FAILURE);
	if (argv[1][0] == '/')
	{
		err = _change_absolute_address(argv[1]);
		if (err)
			return (EXIT_FAILURE);
		_modify_related_env(vars);
		return (0);
	}
	err = chdir(argv[1]);
	if (err)
		return (EXIT_FAILURE);
	_modify_related_env(vars);
	return (EXIT_SUCCESS);
}

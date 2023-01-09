/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:42:08 by klew              #+#    #+#             */
/*   Updated: 2023/01/09 12:44:42 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "Minishell>> "

typedef struct s_pipex
{
	int	new_pipe[2];
	int	last_pipe;
	int	am_cmds;
	int	iter;
	int	heredoc;
}	t_pipex;

typedef struct s_minishell
{
	char	*line;
	char	**cmds;
	char	**env;
	int		exit_code;
	int		stdin_fd;
	int		stdout_fd;
	int		sig;
	t_pipex	pipex;
}	t_minishell;


#endif
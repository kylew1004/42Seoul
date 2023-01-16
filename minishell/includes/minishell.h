/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:42:08 by klew              #+#    #+#             */
/*   Updated: 2023/01/16 14:04:56 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "Minishell>> "
# define EOF -1

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>


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

//Syscalls
int		ft_execsys(char **cmd_words, t_minishell *minishell);
void	ft_dupstds(int in, int out);
int		ft_pipex(char **cmds, t_pipex pipex, t_minishell minishell);

//Parse and lex
int		handle_cmd(char *cmd, t_minishell *minishell, int piped);
char	**add_path(char **cmd, char **env);
int		check_tokens(char *line, t_minishell *minishell);
char	**ft_split_shell(char *s, char c);
void	parse(t_minishell *minishell);
char	**ft_split_cmd(char const *s, char c);

//Utils
char	*ft_strdup_shell(const char *s1);
char	*ft_strjoin_shell(char const *s1, char const *s2);
char	*strip_quotes(char *s);
char	*skip_quote(char *s);
char	*skip_whitespace(char *line);
int		error_handle(char const *s);

//Signals
void	signals(void);
void	sigint_handler_in_process(int sig);
void	sigquit_handler_in_process(int sig);
void	sigint_handler_heredoc(int sig);
void	sig_in_process(char *cmd);

#endif
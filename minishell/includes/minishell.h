/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:42:08 by klew              #+#    #+#             */
/*   Updated: 2023/01/21 16:06:23 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

# define ERROR 1
# define NO_ERROR 0
# define EXIT_STATUS_BUILTIN_EXIT_ARG_NON_NUMERIC 255

# define TRUE 1
# define FALSE 0

# define IN	0
# define OUT 1

# define PROMPT "Minishell>> "

typedef struct s_pipex
{
	int	new_pipe[2];
	int	last_pipe;
	int	am_cmds;
	int	iter;
}	t_pipex;

typedef t_list	t_var_list;

typedef struct s_minishell
{
	char		*line;
	char		**cmds;
	char		**env;
	t_var_list	*vars;
	int			exit_code;
	int			stdin_fd;
	int			stdout_fd;
	int			redir[2];
	int			last_heredoc;
	int			sig;
	t_pipex		pipex;
}	t_minishell;

typedef enum e_var_type {
	REG = 0,
	ENV = 1,
	EPT = 2
}	t_var_type;

typedef struct s_variable {
	char		*key;
	char		*value;
	t_var_type	type;
}	t_variable;

//Syscalls
int			ft_execsys(char **cmd_words, t_minishell *minishell);
void		ft_dupstds(int in, int out);
int			ft_pipex(char **cmds, t_pipex pipex, t_minishell minishell);
void		ft_dupstds(int in, int out);

//Parse and lex
int			handle_cmd(char *cmd, t_minishell *minishell, int piped);
char		**add_path(char **cmd, char **env);
int			check_tokens(char *line, t_minishell *minishell);
char		**ft_split_shell(char *s, char c);
void		parse(t_minishell *minishell);
char		**ft_split_cmd(char const *s, char c);

//Utils
char		*ft_strdup_shell(const char *s1);
char		*ft_strjoin_shell(char const *s1, char const *s2);
char		**ft_split_cmd(char const *s, char c);
char		*strip_quotes(char *s);
char		*ft_strchr_var(const char *s, int c);
char		*skip_quote(char *s);
char		*skip_quote2(char *s, int *i);
char		*skip_whitespace(char *line);
int			error_handle(char const *s);
void		free_ptrarray(char **cmd);

//Signals
void		signals(void);
void		sig_default(void);
void		sig_ignore(void);
void		sigint_handler_heredoc(int sig);

//Builtin & EXEC
int			builtin_echo(char **argv);
int			builtin_cd(char **argv, t_var_list *vars);
int			builtin_pwd(void);
int			builtin_exit(char **argv);
int			builtin_env(char **argv, t_var_list *vars);
int			builtin_export(char **argv, t_var_list *vars);
int			builtin_unset(char **argv, t_var_list *vars);
int			search_builtin(char **cmd_words, t_minishell *minishell);
int			control_execute(char **cmds, t_minishell *minishell, int piped);
char		**get_paths(char **envs);
int			is_builtin_cmd(const char *cmd);

//Variable
int			sort_alphabet_ascending(t_variable *var_arr, int left, int right);
t_variable	*parse_variable(const char *var_str, t_var_type type);
void		free_variable(void *var);
int			check_valid_identifier(const char *key);
int			init_enviroment_vars(t_var_list **env, char *envp[]);
t_variable	*find_variable(t_var_list *vars, const char *key);
char		**make_environment(t_var_list *vars);

//Redirection
int			redirection(char **redirect_str, t_minishell *minishell);
int			heredoc(const char *delim, t_minishell *minishell);
char		**tokenize_redirect(const char *redir_str);
int			control_redirect(const char *redir_str, t_minishell *minishell);
char		**get_splitted_redirect(char *redir_cmd);
int			redirect_cmd(char *cmd, t_minishell *minishell);
char		*remove_redirections(char *cmd);
int			ft_strcmp(const char *str1, const char *str2);
int			run_heredoc(char **splitted, t_minishell *minishell);

//Expensions
char		*expansions(char *s, t_minishell *minishell);
void		sub_vars(char *new_s, char *s, char **vars);
int			conv_vars(char **vars, t_minishell *minishell);
int			len_array(char	**a);
char		*conv_var(char *s, t_minishell *minishell);
char		*skip_var_name(char *s);
char		*ft_getenv(char *var, t_minishell *minishell);

#endif

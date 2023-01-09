/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:05:15 by klew              #+#    #+#             */
/*   Updated: 2023/01/09 13:03:51 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>

void	sigint_handler_in_process(int sig)
{
	(void) sig;
	printf("\n");
}

void	sigquit_handler_in_process(int sig)
{
	printf("Quit: %d\n", sig);
}

void	sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sig_in_process(char *cmd)
{
	if (!strncmp(cmd, "./minishell", 12) || !strncmp(cmd, "bash", 5))
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, sigint_handler_in_process);
		signal(SIGQUIT, sigquit_handler_in_process);
	}
}

void	signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

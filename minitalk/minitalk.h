/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:31:22 by klew              #+#    #+#             */
/*   Updated: 2022/09/16 13:01:10 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	char	x;
	int		client_pid;
}	t_data;

int		ft_atoi(const char *str);
void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	ft_putnbr(int n);
void	reset_data(void);
void	handler(int sig, siginfo_t *info, void *ucontext);

#endif
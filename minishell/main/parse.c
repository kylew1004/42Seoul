/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:41 by klew              #+#    #+#             */
/*   Updated: 2023/01/16 09:41:29 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse(t_minishell *minishell)   //t_shell_variable
{
	if (!check_tokens(minishell->line, minishell))
		return ;
	// minishell->cmds = ft_split_shell(minishell->line, '|');


	free(minishell->cmds);
	return ;
}

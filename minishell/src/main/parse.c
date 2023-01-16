/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:41 by klew              #+#    #+#             */
/*   Updated: 2023/01/16 14:11:57 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_minishell *minishell)   //t_shell_variable
{
	if (!check_tokens(minishell->line, minishell))
		return ;
	minishell->cmds = ft_split_shell(minishell->line, '|');


	//free(minishell->cmds);
	return ;
}

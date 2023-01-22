/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:37:41 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/20 01:39:09 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*puc1;
	unsigned char	*puc2;
	int				i;

	puc1 = (unsigned char *)str1;
	puc2 = (unsigned char *)str2;
	i = 0;
	while (puc1[i] && puc2[i] && puc1[i] == puc2[i])
		++i;
	return (puc1[i] - puc2[i]);
}

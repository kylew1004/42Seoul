/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:09:25 by klew              #+#    #+#             */
/*   Updated: 2023/01/19 23:32:55 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*skip_quote2(char *s, int *i)
{
	char	c;

	c = *s;
	s++;
	if (i)
		*i = *i + 1;
	while (*s != c && *s)
	{
		s++;
		if (i)
			*i = *i + 1;
	}
	return (s);
}

int	len_wtht_quote(char const *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '\"')
		{
			s = skip_quote2((char *)s, &len);
			len--;
		}
		s++;
		if (*s && *s != '\'' && *s != '\"')
			len++;
	}
	return (len);
}

void	copy_stripped_s(char *new_s, char *s)
{
	int	len;

	while (*s)
	{
		len = 0;
		if (*s == '\'' || *s == '\"')
		{
			skip_quote2((char *)s, &len);
			s++;
			ft_strlcpy(new_s, s, len);
			s += len;
			new_s += len - 1;
		}
		else
		{
			*new_s = *s;
			new_s++;
			s++;
		}
	}
	*new_s = 0;
}

char	*strip_quotes(char *s)
{
	char	*new_s;
	int		len;

	len = len_wtht_quote(s);
	new_s = ft_calloc(len + 1, sizeof(char *));
	if (!new_s)
		error_handle("Malloc");
	copy_stripped_s(new_s, s);
	free(s);
	return (new_s);
}

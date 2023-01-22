/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:41:42 by klew              #+#    #+#             */
/*   Updated: 2023/01/21 16:08:40 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*skip_whitespace(char *line)
{
	while (check_set(*line, "\t "))
		line++;
	return (line);
}

char	*ft_strchr_var(const char *s, int c)
{
	int	flag_double;

	flag_double = 0;
	while (*s)
	{
		if (*s == '\"')
		{
			if (flag_double)
				flag_double = 0;
			else
				flag_double = 1;
		}
		if (*s == '\'' && !flag_double)
			s = skip_quote((char *)s);
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*skip_quote(char *s)
{
	char	c;

	c = *s;
	s++;
	while (*s != c && *s)
		s++;
	return (s);
}

char	*ft_strdup_shell(const char *s1)
{
	int		len;
	void	*dst;

	len = ft_strlen(s1) + 1;
	dst = malloc(len * sizeof(char));
	if (!dst)
		error_handle("Malloc");
	return (ft_memcpy(dst, s1, len));
}

char	*ft_strjoin_shell(char const *s1, char const *s2)
{
	char			*dst;
	unsigned int	dsize;

	if (!s1 || !s2)
		return (0);
	dsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = ft_calloc(dsize, sizeof(char));
	if (dst == NULL)
		error_handle("Malloc");
	ft_strlcpy(dst, s1, dsize);
	ft_strlcat(dst, s2, dsize);
	return (dst);
}

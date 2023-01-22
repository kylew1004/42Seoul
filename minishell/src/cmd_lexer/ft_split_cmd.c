/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:42:02 by klew              #+#    #+#             */
/*   Updated: 2023/01/19 23:33:10 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fr_wrds(char **words, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(words[j]);
		j++;
	}
	free(words);
}

static char	*fll_wrd(char *w, char const *s, char c)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	while (s[len] != c && s[len])
	{
		if (s[len] == '\'' || s[len] == '\"')
			skip_quote2((char *)&(s[len]), &len);
		len++;
	}
	w = ft_calloc(len + 1, sizeof(char));
	if (!w)
		error_handle("Malloc");
	ft_strlcpy(w, s, len + 1);
	if (ft_strchr(w, '\'') || ft_strchr(w, '\"'))
		w = strip_quotes(w);
	return (w);
}

static const char	*next_w(char const *s, char c)
{
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		if (*s == '\'' || *s == '\"')
			s = skip_quote((char *)s);
		s++;
	}
	return (s);
}

static int	wrd_cntr(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\'' || *s == '\"')
			s = skip_quote((char *)s);
		if (*s)
			i++;
		while (*s != c && *s)
		{
			s++;
			if (*s == '\'' || *s == '\"')
				s = skip_quote((char *)s);
		}
	}
	return (i);
}

char	**ft_split_cmd(char const *s, char c)
{
	char	**words;
	int		i;
	int		aw;

	if (!s)
		return (0);
	aw = wrd_cntr(s, c);
	words = ft_calloc((aw + 1), sizeof(char *));
	if (!words)
		error_handle("Malloc");
	i = 0;
	while (i < aw)
	{
		words[i] = fll_wrd(words[i], s, c);
		if (!words[i])
		{
			fr_wrds(words, i);
			return (0);
		}
		s = next_w(s, c);
		i++;
	}
	words[i] = NULL;
	return (words);
}

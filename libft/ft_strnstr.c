/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:44:38 by klew              #+#    #+#             */
/*   Updated: 2022/04/26 16:06:48 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char *str, const char *find, size_t len, size_t strindex)
{
	size_t	index;

	index = 0;
	while (find[index] != '\0')
	{
		if (strindex >= len)
		{
			return (0);
		}
		if (find[index] != str[strindex])
		{
			return (0);
		}
		strindex++;
		index++;
	}
	return (1);
}

char	*ft_strnstr(const char *strr, const char *find, size_t len)
{
	size_t	strindex;
	char	*str;

	str = (char *)(strr);
	strindex = 0;
	if (*find == 0)
		return (str);
	while (str[strindex] != '\0')
	{
		if (ft_find(str, find, len, strindex) == 0)
		{
			strindex++;
		}
		else if (ft_find(str, find, len, strindex) == 1)
		{
			return (&str[strindex]);
		}
	}
	return (NULL);
}

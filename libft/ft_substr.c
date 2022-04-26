/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:09:53 by klew              #+#    #+#             */
/*   Updated: 2022/04/26 22:06:00 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	strindex;
	unsigned int	sindex;

	sindex = 0;
	strindex = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		return (NULL);
	}
	while (s[sindex] != '\0')
	{
		if (sindex >= start && strindex < len)
		{
			str[strindex++] = s[sindex];
		}
		sindex++;
	}
	str[strindex] = '\0';
	return (str);
}

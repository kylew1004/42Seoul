/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:44:38 by klew              #+#    #+#             */
/*   Updated: 2022/04/20 17:23:57 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	int		i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < (int)(len - needle_len))
	{
		if (haystack[i] == needle[0])
			if (!ft_strncmp(haystack + i, needle, needle_len))
				return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

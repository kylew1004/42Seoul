/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:09:53 by klew              #+#    #+#             */
/*   Updated: 2022/04/20 17:22:05 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!(ptr))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (j < len && i >= start)
		{
				ptr[j] = s[i];
				j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

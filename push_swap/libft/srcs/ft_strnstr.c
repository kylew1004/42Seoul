/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:07:41 by klew              #+#    #+#             */
/*   Updated: 2022/11/15 13:07:42 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (!n[0])
		return ((char *)h);
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while ((h[i + j] == n[j]) && (i + j < len))
		{
			j++;
			if (!n[j])
				return ((char *)h + i);
		}
		i++;
	}
	return (NULL);
}

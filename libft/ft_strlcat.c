/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:30:55 by klew              #+#    #+#             */
/*   Updated: 2022/04/20 17:15:39 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = 0;
	while (dest[i] && i < dstsize)
		i++;
	while (src[tmp] && (i + tmp + 1) < dstsize)
	{
		dest[i + tmp] = src[tmp];
		tmp++;
	}
	if (i < dstsize)
		dest[i + tmp] = '\0';
	return (i + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:13:43 by klew              #+#    #+#             */
/*   Updated: 2022/03/27 18:29:10 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (!dst && !src)
		return (0);
	new_dst = dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*new_dst++ = *new_src++;
	return (dst);
}

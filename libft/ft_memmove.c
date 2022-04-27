/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:31:16 by klew              #+#    #+#             */
/*   Updated: 2022/04/21 18:36:51 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if ((size_t)(dst - src) >= len)
		return (ft_memcpy(dst, src, len));
	while (len--)
		*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	return (dst);
}

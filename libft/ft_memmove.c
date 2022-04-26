/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:31:16 by klew              #+#    #+#             */
/*   Updated: 2022/04/26 20:19:31 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	index;

	if (!src && !dest)
		return (NULL);
		index = 0;
	if ((unsigned char *)dest < (unsigned char *)src)
	{
		while (index < num)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	else
	{
		while (index < num)
		{
			((unsigned char *)dest)[num - 1 - index] =
			((unsigned char *)src)[num - 1 - index];
			index++;
		}
	}
	return ((unsigned char *)dest);
}

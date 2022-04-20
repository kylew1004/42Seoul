/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:10:27 by klew              #+#    #+#             */
/*   Updated: 2022/04/20 16:50:42 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;
	unsigned char	c;

	ptr_str = (unsigned char *) ptr;
	c = (unsigned char) value;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == c)
			return ((void *)ptr_str + i);
		i++;
	}
	return (NULL);
}

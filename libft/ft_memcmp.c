/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:07:08 by klew              #+#    #+#             */
/*   Updated: 2022/04/21 18:34:10 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	res;

	while (n--)
	{
		res = *((unsigned char *)s1++) - *((unsigned char *)s2++);
		if ((res))
			return (res);
	}
	return (0);
}

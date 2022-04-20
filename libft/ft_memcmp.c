/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:07:08 by klew              #+#    #+#             */
/*   Updated: 2022/04/20 16:51:25 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*prt_srt1;
	unsigned char	*prt_str2;
	size_t			i;

	ptr_str1 = (unsigned char *) ptr1;
	ptr_srt2 = (unsigned char *) ptr2;
	i = 0;
	while (i < n)
	{
		if (ptr_str1[i] != ptr_str2[i])
			return (ptr_str1[i] - ptr_str2[i]);
		i++;
	}
	return (0);
}

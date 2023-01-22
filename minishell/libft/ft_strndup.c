/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:35:31 by junhelee          #+#    #+#             */
/*   Updated: 2023/01/16 16:35:40 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;

	if (!s1)
		return (NULL);
	result = (char *)malloc((n + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, n + 1);
	return (result);
}

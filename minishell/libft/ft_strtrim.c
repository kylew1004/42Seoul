/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:17:21 by klew              #+#    #+#             */
/*   Updated: 2023/01/15 21:22:20 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(unsigned char s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*result;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	begin = 0;
	while (s1[begin] != '\0' && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	result = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!(result))
		return (NULL);
	i = 0;
	while (begin < end)
		result[i++] = s1[begin++];
	result[i] = '\0';
	return (result);
}

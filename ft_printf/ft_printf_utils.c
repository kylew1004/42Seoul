/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:50:29 by klew              #+#    #+#             */
/*   Updated: 2022/07/09 16:00:24 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_cnt(unsigned int c)
{
	int	i;

	i = 0;
	while (c > 0)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

int	ft_array_cnt(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_array_cnt("(null)"));
	while (str[len] != '\0')
		len += ft_putchars(str[len]);
	return (len);
}

int	ft_hex_cnt(unsigned int hex_num)
{
	int	i;

	i = 0;
	if (hex_num == 0)
		return (1);
	while (hex_num > 0)
	{
		hex_num = (hex_num / 16);
		i++;
	}
	return (i);
}

int	ft_putchars(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_uitoa(unsigned int n)
{
	int			len;
	char		*str;

	len = ft_num_cnt(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (n == 0)
	{
		free(str);
		return (write(1, "0", 1));
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	len = ft_array_cnt(str);
	free(str);
	return (len);
}

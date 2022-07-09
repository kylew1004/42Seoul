/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:13:16 by klew              #+#    #+#             */
/*   Updated: 2022/07/09 16:00:01 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_printer(unsigned long n)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ptr_printer(n / 16);
		ptr_printer(n % 16);
	}
	else
		ft_putchars(a[n]);
	free(a);
	return (0);
}

int	ptr_print(unsigned long n)
{
	int	i;

	i = 1;
	ft_putchars('0');
	ft_putchars('x');
	ptr_printer(n);
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 2);
}

int	hexfunc(unsigned int hex_num, char c)
{
	char			*str;
	int				len;
	char			*digit;
	int				i;

	if (c == 'X')
		digit = "0123456789ABCDEF";
	else
		digit = "0123456789abcdef";
	len = ft_hex_cnt(hex_num);
	i = len;
	str = calloc(len, 1);
	if (hex_num == 0)
		return (write(1, "0", 1));
	while (hex_num > 0)
	{
		str[--i] = digit[hex_num % 16];
		hex_num = hex_num / 16;
	}
	ft_array_cnt(str);
	free(str);
	return (len);
}

int	printing(va_list ap, int info)
{
	char	*a;
	int		i;

	i = 0;
	if (info == 'c')
		i += ft_putchars(va_arg(ap, int));
	else if (info == 'd' || info == 'i')
	{
		a = ft_itoa(va_arg(ap, int));
		i += ft_array_cnt(a);
		free(a);
	}
	else if (info == 's')
		i += ft_array_cnt(va_arg(ap, char *));
	else if (info == 'p')
		i += ptr_print(va_arg(ap, unsigned long));
	else if (info == 'x' || info == 'X')
		i += hexfunc(va_arg(ap, unsigned int), info);
	else if (info == 'u')
		i += ft_uitoa(va_arg(ap, unsigned int));
	else if (info == '%')
		i += ft_putchars('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += printing(ap, str[i]);
		}
		else
		{
			ft_putchars(str[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

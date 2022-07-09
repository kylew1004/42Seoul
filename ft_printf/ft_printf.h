/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:43:49 by klew              #+#    #+#             */
/*   Updated: 2022/07/09 16:10:37 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_num_cnt(unsigned int c);
int	ft_hex_cnt(unsigned int hex_num);
int	ft_putchars(char c);
int	hexfunc(unsigned int hex_num, char c);
int	printing(va_list ap, int info);
int	ft_printf(const char *str, ...);
int	ft_uitoa(unsigned int n);
int	ft_array_cnt(char *str);
int	ptr_printer(unsigned long n);
int	ptr_print(unsigned long n);

#endif

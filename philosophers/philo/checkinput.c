/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:21 by klew              #+#    #+#             */
/*   Updated: 2022/12/12 10:43:06 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_input_a_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	is_input_valid(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!is_input_a_digit(av[i]))
			return (printf("%s\n", ERR_DIGIT), false);
		nb = convert_str_to_int(av[i]);
		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (printf("%s\n", ERR_PHILONR), false);
		if (i != 1 && nb == 0)
			return (printf("%s\n", ERR_ZERO), false);
		if (i != 1 && nb == -1)
			return (printf("%s\n", ERR_MAXINT), false);
		i++;
	}
	return (true);
}

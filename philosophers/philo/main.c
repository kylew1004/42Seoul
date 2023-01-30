/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:11 by klew              #+#    #+#             */
/*   Updated: 2022/12/12 10:46:19 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("%s\n", ERR_ARG), EXIT_FAILURE);
	if (is_input_valid(ac, av) == false)
		return (EXIT_FAILURE);
	if (initialize(&data, av) == false)
		return (EXIT_FAILURE);
	if (simulation(&data) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

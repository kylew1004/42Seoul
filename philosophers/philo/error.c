/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:21 by klew              #+#    #+#             */
/*   Updated: 2022/12/12 10:43:04 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
	if (data->threads)
		free(data->threads);
}

void	destroy_mutex_philo(t_data *data, int index)
{
	int	i;

	i = index;
	while (i > 0)
	{
		i--;
		pthread_mutex_destroy(&data->philo[i].lock_eating);
	}
}

void	destroy_mutex_forks(t_data *data, int index)
{
	int	i;

	i = index;
	destroy_mutex_philo(data, data->nr_philos);
	while (i > 0)
	{
		i--;
		pthread_mutex_destroy(&data->forks[i]);
	}
}

void	destroy_mutex_write_and_fork(t_data *data, int index)
{
	destroy_mutex_forks(data, index);
	pthread_mutex_destroy(&data->lock_write);
}

void	destroy_mutex_all(t_data *data, int index)
{
	destroy_mutex_write_and_fork(data, index);
	pthread_mutex_destroy(&data->lock_dead);
}

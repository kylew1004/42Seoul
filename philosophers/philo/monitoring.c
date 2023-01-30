/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:11 by klew              #+#    #+#             */
/*   Updated: 2022/12/12 10:43:12 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_dead(t_data *data)
{
	pthread_mutex_lock(&(data->lock_dead));
	if (data->dead == true)
	{
		pthread_mutex_unlock(&(data->lock_dead));
		return (true);
	}
	pthread_mutex_unlock(&(data->lock_dead));
	return (false);
}

bool	check_if_died(t_data *data, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->lock_eating);
	if (get_time() - philo->time_last_meal >= data->time_to_die)
	{
		pthread_mutex_unlock(&philo->lock_eating);
		pthread_mutex_lock(&data->lock_dead);
		data->dead = true;
		pthread_mutex_unlock(&data->lock_dead);
		time = get_time() - data->start_time;
		printf("%ld %d died\n", time, philo->philo_id);
		return (true);
	}
	pthread_mutex_unlock(&philo->lock_eating);
	return (false);
}

static bool	check_ate_enough(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_eating);
	if (philo->times_eaten >= data->times_must_eat)
	{
		pthread_mutex_unlock(&philo->lock_eating);
		return (true);
	}
	pthread_mutex_unlock(&philo->lock_eating);
	return (false);
}

void	monitoring(t_data *data)
{
	int	i;

	while (true)
	{
		i = 0;
		data->philos_done_eating = 0;
		while (i < data->nr_philos)
		{
			if (check_ate_enough(data, &data->philo[i]) == true)
				data->philos_done_eating++;
			if (check_if_died(data, &data->philo[i]) == true)
				return ;
			usleep(250);
			i++;
		}
		if (data->times_must_eat != -1
			&& data->philos_done_eating == data->nr_philos)
		{
			pthread_mutex_lock(&data->lock_dead);
			data->dead = true;
			pthread_mutex_unlock(&data->lock_dead);
			return ;
		}
		usleep(500);
	}
}

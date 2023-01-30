/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:55:52 by klew              #+#    #+#             */
/*   Updated: 2022/12/12 10:43:07 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_data(t_data *data, char **av)
{
	if (!data)
		return (false);
	data->nr_philos = convert_str_to_int(av[1]);
	data->time_to_die = convert_str_to_int(av[2]);
	data->time_to_eat = convert_str_to_int(av[3]);
	data->time_to_sleep = convert_str_to_int(av[4]);
	data->times_must_eat = -1;
	if (av[5])
		data->times_must_eat = convert_str_to_int(av[5]);
	data->philos_done_eating = 0;
	data->start_time = get_time();
	data->dead = false;
	return (true);
}

static void	asign_forks(t_philo *philo)
{
	int	fork_id_left;
	int	fork_id_right;

	fork_id_left = philo->philo_id - 1;
	fork_id_right = philo->philo_id;
	if (fork_id_right == philo->data->nr_philos)
		fork_id_right = 0;
	philo->fork_left = fork_id_left;
	philo->fork_right = fork_id_right;
}

static bool	init_philosopher(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nr_philos);
	if (!data->philo)
		return (false);
	i = 0;
	while (i < data->nr_philos)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].data = data;
		data->philo[i].times_eaten = 0;
		data->philo[i].time_last_meal = get_time();
		asign_forks(&data->philo[i]);
		if (pthread_mutex_init(&data->philo[i].lock_eating, NULL))
			return (destroy_mutex_philo(data, i), false);
		i++;
	}
	return (true);
}

static bool	init_mutexes(t_data *data)
{
	int	i;

	if (!data)
		return (false);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nr_philos);
	if (!data->forks)
		return (false);
	i = 0;
	while (i < data->nr_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (destroy_mutex_forks(data, i), false);
		i++;
	}
	if (pthread_mutex_init(&data->lock_write, NULL))
		return (destroy_mutex_forks(data, i), false);
	if (pthread_mutex_init(&data->lock_dead, NULL))
		return (destroy_mutex_write_and_fork(data, i), false);
	return (true);
}

bool	initialize(t_data *data, char **av)
{
	if (init_data(data, av) == false)
		return (printf("%s\n", ERR_DATA), false);
	if (init_philosopher(data) == false)
		return (printf("%s\n", ERR_PHILO), false);
	if (init_mutexes(data) == false)
	{
		free_data(data);
		return (printf("%s\n", ERR_MUTEX), false);
	}
	return (true);
}

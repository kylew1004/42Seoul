/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:21 by klew              #+#    #+#             */
/*   Updated: 2022/12/12 10:43:16 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	convert_str_to_int(char *str)
{
	unsigned long	nb;
	int				i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	time_action(unsigned long time_action, t_data *data)
{
	unsigned long	start;

	start = get_time();
	while (get_time() - start < time_action)
	{
		if (check_dead(data) == true)
			return ;
		usleep(200);
	}
}

bool	philo_print(t_philo *philo, char *str)
{
	unsigned long	time;

	pthread_mutex_lock(&philo->data->lock_write);
	if (check_dead(philo->data) == true)
	{
		pthread_mutex_unlock(&philo->data->lock_write);
		return (false);
	}
	time = get_time();
	printf("%ld %d %s\n", time - (philo->data->start_time),
		philo->philo_id, str);
	pthread_mutex_unlock(&philo->data->lock_write);
	return (true);
}

void	join_threads(t_data *data, int i)
{
	while (i > 0)
	{
		i--;
		pthread_join(data->threads[i], NULL);
	}
}

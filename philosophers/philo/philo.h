/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:21 by klew              #+#    #+#             */
/*   Updated: 2022/12/12 10:43:15 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILOS	200
# define ERR_ARG		"Error: Wrong amount of arguments."
# define ERR_DIGIT		"Error: Input contains not only digits."
# define ERR_PHILONR	"Error: There must be between 1 and 200 philosophers."
# define ERR_ZERO		"Error: Arguments can't be zero."
# define ERR_MAXINT		"Error: Arguments can't be bigger than MAX_INT."
# define ERR_DATA		"Error: Something went wrong initializing data."
# define ERR_PHILO		"Error: Something went wrong initializing philosopher."
# define ERR_MUTEX		"Error: Something went wrong initializing mutexes."

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct s_data {
	int				nr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				philos_done_eating;
	long			start_time;
	bool			dead;
	pthread_t		*threads;

	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	lock_dead;

	t_philo			*philo;
};

struct s_philo {
	t_data			*data;
	int				philo_id;
	int				times_eaten;
	long			time_last_meal;
	bool			done_eating;
	int				fork_left;
	int				fork_right;
	pthread_mutex_t	lock_eating;
};

bool	is_input_valid(int ac, char **av);

bool	initialize(t_data *data, char **av);

bool	simulation(t_data *data);

void	one_philo(t_philo *philo);
bool	philo_sleep(t_philo *philo);
bool	philo_eat(t_philo *philo);
bool	philo_think(t_philo *philo);

bool	check_dead(t_data *data);
void	monitoring(t_data *data);

void	free_data(t_data *data);
void	destroy_mutex_philo(t_data *data, int index);
void	destroy_mutex_forks(t_data *data, int index);
void	destroy_mutex_write_and_fork(t_data *data, int index);
void	destroy_mutex_all(t_data *data, int index);

int		convert_str_to_int(char *str);
long	get_time(void);
void	time_action(unsigned long time_action, t_data *data);
bool	philo_print(t_philo *philo, char *str);
void	join_threads(t_data *data, int i);

#endif
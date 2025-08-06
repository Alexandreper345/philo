/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/08/06 20:55:44 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <sys/stat.h>

typedef pthread_mutex_t	t_mtx;
typedef long long		t_time;
typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t	id_thread;
	int			id;
	int			size_philos_eat;
	int			is_full;
	t_time		last_time_meal;
	t_time		time_die;
	t_time		time_eat;
	t_time		time_sleep;
	t_mtx		*fork_left;
	t_mtx		*fork_right;
	t_mtx		*print_mutex;
	t_mtx		*stop_mutex;
	t_mtx		*dead_philo;
	t_time		start_time;
	t_table		*table;

}t_philo;

typedef struct s_table
{
	int			stop_simulation;
	int			forks;
	int			count_philos;
	int			size_philos_eat;
	int			philos_full;
	t_philo		**philos;
	t_time		time_die;
	t_time		time_eat;
	t_time		time_sleep;
	t_time		start_time;
	t_mtx		stop_mutex;
	t_mtx		dead_philo;
	t_mtx		print_mutex;

}t_table;

t_table		*init_table(t_table **table, int argc, char **argv);
t_mtx		*create_array_mutex(t_table *table);
t_time		get_time(void);
t_time		philo_get_last_meal(t_philo	*philo, t_mtx *mutex);
t_philo		*init_philos(t_table *table, int i, t_mtx *array);
int			isnumeric(char *value);
int			ft_atoi(const char *nptr);
void		stop_simulation(t_table *table, t_mtx *stop_mutex);
int			forced_usleep(size_t time, t_philo *philo);
int			simulation_stopped(t_table *table, t_mtx *stop_mutex);
int			is_dead(t_philo *philo);
void		*philo_routine(void	*ptr);
void		*one_philos(void *ptr);
void		printed_mutex(t_philo *philo, char *str);
int			philos_full(t_philo *philo);
void		*monitor_routine(void *arg);

#endif
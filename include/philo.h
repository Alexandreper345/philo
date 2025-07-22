/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/21 21:59:16 by alda-sil         ###   ########.fr       */
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

typedef pthread_mutex_t t_mtx;
typedef long long		t_time;

typedef	enum s_state 
{
	WAITING,
	HUNGER,
	SLEEP,
	EATING,
	THINKING,
	DEAD,
	FULL
} t_state;

typedef struct s_philo
{
	pthread_t	id_thread;
	int			id;
	t_time		last_time_meal;
	t_state		state;
	t_time		time_die;
	t_time		time_eat;
	t_time		time_sleep;
	t_mtx		*fork_left;
	t_mtx		*fork_right;
	t_mtx		print_mutex;
	t_time		start_time;
	
} t_philo;

typedef struct s_table
{
	bool		philo_die;
	int			forks;
	int			count_philos;
	int			size_philos_eat;
	t_philo		**philos;
	t_time		time_die;
	t_time		time_eat;
	t_time		time_sleep;
	t_time		start_time;
} t_table;

t_table	*init_table(t_table **table, int argc, char **argv);
t_mtx	*create_array_mutex(t_table *table);
t_time	get_time(void);
t_state	philo_get_state(t_philo *philo);
int		isnumeric(char *value);
int		ft_atoi(const char *nptr);
void	philo_set_state(t_philo *philo, t_state type);
void	*philo_routine(void	*ptr);
void 	forced_usleep(size_t time);
void	printed_mutex(t_philo *philo, char *str);

#endif
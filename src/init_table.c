/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:53:55 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/24 15:29:06 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_time	get_time(void)
{
	struct timeval tv;
	t_time	time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (time);
}

t_table	*init_table(t_table **table, int argc, char **argv)
{
	t_philo **philo;

	*table = (t_table *)malloc(sizeof(t_table));
	philo = (t_philo **)malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	if (!*table || !philo)
		return (NULL);
	pthread_mutex_init(&(*table)->print_mutex, NULL);
	pthread_mutex_init(&(*table)->stop_mutex, NULL);
	pthread_mutex_init(&(*table)->dead_philo, NULL);
	(*table)->forks = ft_atoi(argv[1]);
	(*table)->count_philos = ft_atoi(argv[1]);
	(*table)->stop_simulation = 0;
	(*table)->time_die = ft_atoi(argv[2]);
	(*table)->time_eat = ft_atoi(argv[3]);
	(*table)->time_sleep = ft_atoi(argv[4]);
	(*table)->philos = philo;
	if (argc == 6)
		(*table)->size_philos_eat = ft_atoi(argv[5]);
	(*table)->start_time = get_time();
	return (*table);
}

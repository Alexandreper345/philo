/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:00:37 by alda-sil          #+#    #+#             */
/*   Updated: 2025/08/05 18:43:04 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_mtx	*create_array_mutex(t_table *table)
{
	t_mtx	*array;
	int		i;

	i = -1;
	array =	(t_mtx *)malloc(sizeof(t_mtx) * table->count_philos);
	if (!array)
		return (NULL);
	while (++i < table->count_philos)
		pthread_mutex_init(&array[i], NULL);
	return (array);
}

void	stop_simulation(t_table *table, t_mtx *stop_mutex)
{
	pthread_mutex_lock(stop_mutex);
	table->stop_simulation = 1;
	pthread_mutex_unlock(stop_mutex);
}

int	simulation_stopped(t_table *table, t_mtx *stop_mutex)
{
	int	stop;

	pthread_mutex_lock(stop_mutex);
	stop = table->stop_simulation;
	pthread_mutex_unlock(stop_mutex);
	return (stop);
}


t_time	philo_get_last_meal(t_philo	*philo, t_mtx *mutex)
{
	t_time	time;
	
	pthread_mutex_lock(mutex);
	time = philo->last_time_meal;
	pthread_mutex_unlock(mutex);
	return (time);
}

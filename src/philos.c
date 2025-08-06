/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:07:30 by alda-sil          #+#    #+#             */
/*   Updated: 2025/08/05 18:47:02 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	mutex(t_table *table, t_philo *philo)
{
	philo->print_mutex = &table->print_mutex;
	philo->dead_philo = &table->dead_philo;
	philo->stop_mutex = &table->stop_mutex;
}

int	check_philo(t_table *table, t_philo *philo, int i, t_mtx *array)
{
	if (table->size_philos_eat != 0)
		philo->size_philos_eat = table->size_philos_eat;
	if (i == 0)
		philo->fork_right = &array[table->count_philos - 1];
	else
		philo->fork_right = &array[i - 1];
	if (!simulation_stopped(table, philo->stop_mutex))
		return (1);
	return (0);
}

t_philo *init_philos(t_table *table, int i, t_mtx *array)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	mutex(table, philo);
	philo->table = table;	
	philo->id = i + 1;
	philo->time_die = table->time_die;
	philo->time_eat = table->time_eat;
	philo->last_time_meal = get_time();
	philo->time_sleep = table->time_sleep;
	philo->is_full = 0;
	philo->start_time = table->start_time;
	philo->fork_left = &array[i];
	if (check_philo(table, philo, i, array))
		pthread_create(&philo->id_thread, NULL, &philo_routine, (void *)philo);
	return (philo);
}

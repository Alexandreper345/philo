/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:48:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/08/06 21:03:08 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_philo *philo)
{
	t_time	time;
	t_time	last_meal;

	time = get_time();
	last_meal = philo_get_last_meal(philo, philo->print_mutex);
	if (time - last_meal >= philo->time_die)
	{
		pthread_mutex_lock(philo->dead_philo);
		if (!simulation_stopped(philo->table, philo->stop_mutex))
		{
			printed_mutex(philo, "died");
			stop_simulation(philo->table, philo->stop_mutex);
		}
		pthread_mutex_unlock(philo->dead_philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	philos_full(t_philo *philo)
{
	philo->size_philos_eat--;
	if (philo->size_philos_eat <= 0)
	{
		pthread_mutex_lock(philo->dead_philo);
		philo->is_full = 1;
		philo->table->philos_full++;
		if (philo->table->philos_full == philo->table->count_philos)
			stop_simulation(philo->table, philo->stop_mutex);
		pthread_mutex_unlock(philo->dead_philo);
		return (1);
	}
	return (0);
}

int	one_philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printed_mutex(philo, "has taken a fork");
	forced_usleep(philo->time_die, philo);
	pthread_mutex_unlock(philo->fork_left);
	printed_mutex(philo, "died");
	return (EXIT_FAILURE);
}

void	*one_philos(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (one_philo_eating(philo))
		return (NULL);
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;
	t_philo	*philo;
	t_time	last_meal;

	table = (t_table *)arg;
	while (!simulation_stopped(table, &table->stop_mutex))
	{
		i = 0;
		while (i < table->count_philos)
		{
			philo = table->philos[i];
			last_meal = philo_get_last_meal(philo, philo->print_mutex);
			if ((get_time() - last_meal) >= philo->time_die)
			{
				printed_mutex(philo, "died");
				stop_simulation(table, &table->stop_mutex);
				return (NULL);
			}
			i++;
		}
		usleep(500);
	}
	return (NULL);
}

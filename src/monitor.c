/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:48:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/31 23:09:53 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_philo *philo)
{
	if (get_time() - philo_get_last_meal(philo, philo->print_mutex) >= philo->time_die)
	{
		pthread_mutex_lock(&philo->table->dead_philo);
		if (!simulation_stopped(philo->table))
		{
			printed_mutex(philo, "DEAD...");
			stop_simulation(philo->table);
		}
		pthread_mutex_unlock(&philo->table->dead_philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	philos_full(t_philo *philo)
{
	if (philo->size_philos_eat == 0)
	{
		pthread_mutex_lock(&philo->table->dead_philo);
		philo->is_full = 1;
		philo->table->philos_full++;
		if (philo->table->philos_full == philo->table->count_philos)
			stop_simulation(philo->table);
		pthread_mutex_unlock(&philo->table->dead_philo);
		return (1);
	}
	return (0);
}

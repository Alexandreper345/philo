/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:48:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/28 20:01:12 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int	i;

	table = (t_table *)arg;
	while (1)
	{
		if (i == table->count_philos)
			i = 0;
		if (simulation_stopped(table))
		{
			printed_mutex(table->philos[i], "monitor: DEAD...");
			stop_simulation(table);	
			pthread_mutex_unlock(&table->dead_philo);
			return (NULL);
		}
		i++;
		usleep(1);
	}
	return (NULL);
}

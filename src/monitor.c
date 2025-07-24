/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:48:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/24 16:01:38 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int	i;

	table = (t_table *)arg;
	while (!simulation_stopped(table))
	{
		i = 0;
		while (i < table->count_philos)
		{
			if (table->philos[i]->state == DEAD)
			{
				pthread_mutex_lock(&table->dead_philo);
				printed_mutex(table->philos[i], "monitor: DEAD...");
				pthread_mutex_unlock(&table->dead_philo);
				stop_simulation(table);	
				return (NULL);
			}
			i++;
		}
		usleep(1);
	}
	return (NULL);
}

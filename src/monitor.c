/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:48:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/24 16:37:25 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int	i;

	table = (t_table *)arg;
	printf("aqui\n");
	while (!simulation_stopped(table))
	{
		printf("entrou\n");
		i = 0;
		while (i < table->count_philos)
		{
			if (table->philos[i]->state == DEAD)
			{
				printed_mutex(table->philos[i], "monitor: DEAD...");
				stop_simulation(table);	
				pthread_mutex_unlock(&table->dead_philo);
				return (NULL);
			}
			i++;
		}
		usleep(1);
	}
	printf("saiu\n");
	return (NULL);
}

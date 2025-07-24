/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:48:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/23 21:29:38 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	monitor(t_table *table)
{
	int i;
	int	j;
	t_philo	*philo;

	while (1)
	{
		i = 0;
		while (i < table->count_philos)
		{
			philo = table->philos[i];
			if (philo->state == DEAD)
			{
				i = 0;
				while (++i < table->count_philos)
					printed_mutex(table->philos[i], "monitor: DEAD...");
				table->philo_die = true;	
				return ;
			}
			i++;
		}
	}
}

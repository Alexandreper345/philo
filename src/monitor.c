/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:48:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/22 21:18:47 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	monitor(t_table *table)
{
	int	i;
	
	i = -1;
	while (table->philos[++i]->state != DEAD)
	if (table->philos[i]->state == DEAD)
	{
		i = -1;
		while (table->philos[++i])
		{
			printed_mutex(table->philos, "DEAD...");
			table->philos[i]->state = DEAD;
		}
	}
		
}

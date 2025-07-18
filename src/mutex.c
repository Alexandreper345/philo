/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:00:37 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/17 20:46:50 by alda-sil         ###   ########.fr       */
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
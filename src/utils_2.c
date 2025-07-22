/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:00:37 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/21 21:46:29 by alda-sil         ###   ########.fr       */
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

t_state	philo_get_state(t_philo *philo)
{
	return (philo->state);
}
 
void	philo_set_state(t_philo *philo, t_state type)
{
	if (philo->state == WAITING)
		philo->state = WAITING;
	else if (philo->state == SLEEP)
		philo->state = SLEEP;
	else if (philo->state == HUNGER)
		philo->state = HUNGER;
	else if (philo->state == EATING)
		philo->state = EATING;
	else if (philo->state == THINKING)
		philo->state = THINKING;
	else if (philo->state == DEAD)
		philo->state = DEAD;
	else if (philo->state == FULL)
		philo->state = FULL;
}

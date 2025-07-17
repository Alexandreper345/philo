/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/16 21:18:42 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_mutex);
		printf("hello_world {%d}\n", philo->id);
	pthread_mutex_unlock(&philo->fork_mutex);
}
	
void	philo_sleep(void)
{
	printf("SLEEP\n");
}

void	*philo_routine(void	*ptr)
{
	t_philo	*philo;
	
	philo = (t_philo *)ptr;
	philo_eating(philo);
	philo_sleep();

	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/17 22:05:11 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_eating(t_philo *philo)
{
	
	pthread_mutex_lock(philo->fork_left);
	printf("%d pegou o garfo da esquerda\n", philo->id);
	pthread_mutex_lock(philo->fork_right);
	printf("%d pegou o garfo da direita\n", philo->id);

	printf("%d is eating\n", philo->id);
	usleep(5000000);

	pthread_mutex_unlock(philo->fork_right);
	printf("%d soltou o garfo da direita\n", philo->id);
	pthread_mutex_unlock(philo->fork_left);
	printf("%d soltou o garfo da esquerda\n", philo->id);
	
	
}
	
void	philo_sleep(t_philo *philo)
{
	printf("SLEEP\n");
}

void	*philo_routine(void	*ptr)
{
	t_philo	*philo;
	
	philo = (t_philo *)ptr;
	philo_eating(philo);
	//philo_sleep(philo);

	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/21 21:59:12 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		printf("%lld ms %d pegou o garfo da esquerda\n", get_time() - philo->start_time, philo->id);
		pthread_mutex_lock(philo->fork_right);
		printf("%lld ms %d pegou o garfo da direita\n", get_time() - philo->start_time, philo->id);
		printf("%lld ms %d eating...\n", get_time() - philo->start_time, philo->id);
		forced_usleep(philo->time_eat);
		pthread_mutex_unlock(philo->fork_right);
		printf("%lld ms %d soltou o garfo da direita\n", get_time() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->fork_left);
		printf("%lld ms %d soltou o garfo da esquerda\n", get_time() - philo->start_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		printf("%lld ms %d pegou o garfo da direita\n", get_time() - philo->start_time, philo->id);	
		pthread_mutex_lock(philo->fork_left);
		printf("%lld ms %d pegou o garfo da esquerda\n", get_time() - philo->start_time, philo->id);
		printf("%lld ms %d eating...\n", get_time() - philo->start_time, philo->id);
		forced_usleep(philo->time_eat);
		pthread_mutex_unlock(philo->fork_left);
		printf("%lld ms %d soltou o garfo da esquerda\n", get_time() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->fork_right);
		printf("%lld ms %d soltou o garfo da direita\n", get_time() - philo->start_time, philo->id);
	}
}
	
void	philo_sleep(t_philo *philo)
{
	philo_set_state(philo, SLEEP);
	printf("%lld ms  %d SLEEP...\n", get_time() - philo->start_time, philo->id);
	forced_usleep(philo->time_sleep);
}
void	philo_thinking(t_philo *philo)
{
	philo_set_state(philo, THINKING);
	printf("%lld ms %d THINKING...\n", get_time() - philo->start_time, philo->id);
}	

void	*philo_routine(void	*ptr)
{
	t_philo	*philo;
	philo = (t_philo *)ptr;
	t_state state;

	state = philo->state;
	while (1)
	{
		if (state != DEAD || state != FULL)
		{
			mutex
			philo_eating(philo);
			philo_sleep(philo);
			philo_thinking(philo);
			if (get_time() - philo->last_time_meal > philo->time_die)
			{
				philo_set_state(philo, DEAD);
				break;
			}
		}
		usleep(1);
	}
	return (NULL);
}

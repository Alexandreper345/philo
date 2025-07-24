/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/23 21:28:47 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int	left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printed_mutex(philo, "has a left fork");
	pthread_mutex_lock(philo->fork_right);
	printed_mutex(philo, "has a right fork");
	printed_mutex(philo, "eating..");
	if (forced_usleep(philo->time_eat, philo))
		return (EXIT_FAILURE);
	philo->last_time_meal = get_time();
	pthread_mutex_unlock(philo->fork_right);
	printed_mutex(philo, "has a right fork");
	pthread_mutex_unlock(philo->fork_left);
	printed_mutex(philo, "has a left fork");
	return (EXIT_SUCCESS);
}

void philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (left_fork(philo))
			return ;
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		printed_mutex(philo, "has a right fork");
		pthread_mutex_lock(philo->fork_left);
		printed_mutex(philo, "has a left fork");
		printed_mutex(philo, "eating..");
		if (forced_usleep(philo->time_eat, philo))
			return ;
		philo->last_time_meal = get_time();
		pthread_mutex_unlock(philo->fork_left);
		printed_mutex(philo, "has a left fork");
		pthread_mutex_unlock(philo->fork_right);
		printed_mutex(philo, "has a right fork");
	}
}
	
void	philo_sleep(t_philo *philo)
{
	philo_set_state(philo, SLEEP, philo->print_mutex);
	printed_mutex(philo, "SLEEP...");
	if (forced_usleep(philo->time_sleep, philo))
		return ;
}
void	philo_thinking(t_philo *philo)
{
	philo_set_state(philo, THINKING, philo->print_mutex);
	printed_mutex(philo, "THINKING...");
}	

void	*philo_routine(void	*ptr)
{
	t_philo	*philo;
	philo = (t_philo *)ptr;
	t_state state;
	
	state = philo->state;
	while (state != DEAD && state != FULL)
	{
		if (state == THINKING)
			philo_eating(philo);
		else if(state == EATING)
			philo_sleep(philo);
		else if (state == SLEEP)
			philo_thinking(philo);
		if (get_time() - philo_get_state(philo,philo->print_mutex) >= philo->time_die)
		{
			philo_set_state(philo, DEAD, philo->print_mutex);
			break;
		}
		state = philo->state;
		usleep(1);
	}
	return (NULL);
}

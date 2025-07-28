/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/28 20:03:34 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int	left_fork(t_philo *philo)
{
	if (simulation_stopped(philo->table))
        return (EXIT_FAILURE);
	pthread_mutex_lock(philo->fork_left);
	printed_mutex(philo, "has a left fork");
	pthread_mutex_lock(philo->fork_right);
	printed_mutex(philo, "has a right fork");
	philo->last_time_meal = get_time();
	printed_mutex(philo, "eating..");
	if (forced_usleep(philo->time_eat, philo))
	{
		pthread_mutex_unlock(philo->fork_right);
        pthread_mutex_unlock(philo->fork_left);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	return (EXIT_SUCCESS);
}

int philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (left_fork(philo))
			return (EXIT_FAILURE);
	}
	else
	{
		if (simulation_stopped(philo->table))
        return (EXIT_FAILURE);
		pthread_mutex_lock(philo->fork_right);
		printed_mutex(philo, "has a right fork");
		pthread_mutex_lock(philo->fork_left);
		printed_mutex(philo, "has a left fork");
		philo->last_time_meal = get_time();
		printed_mutex(philo, "eating..");
		if (forced_usleep(philo->time_eat, philo))
		{
        	pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
			return (EXIT_FAILURE);
		}
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
	return (EXIT_SUCCESS);
}
	
int	philo_sleep(t_philo *philo)
{
	philo_set_state(philo, SLEEP, philo->print_mutex);
	printed_mutex(philo, "SLEEP...");
	if (forced_usleep(philo->time_sleep, philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int	philo_thinking(t_philo *philo)
{
	philo_set_state(philo, THINKING, philo->print_mutex);
	printed_mutex(philo, "THINKING...");
	if (forced_usleep(1, philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}	

void	*philo_routine(void	*ptr)
{
	t_philo	*philo;
	philo = (t_philo *)ptr;
	t_state state;
	
	state = philo_get_state(philo, philo->print_mutex);
	while (!simulation_stopped(philo->table))
	{
		if (get_time() - philo_get_last_meal(philo, philo->print_mutex) >= philo->time_die)
		{
			pthread_mutex_lock(&philo->table->dead_philo);
			if (!simulation_stopped(philo->table))
			{
				printed_mutex(philo, "DEAD...");
				philo_set_state(philo, DEAD, philo->print_mutex);
				stop_simulation(philo->table);
			}
			pthread_mutex_unlock(&philo->table->dead_philo);
			break;
		}
		if (philo_eating(philo))
			return (NULL);
		if (simulation_stopped(philo->table))
			break ;
		if (philo_sleep(philo))
			return (NULL);
		if (simulation_stopped(philo->table))
			break ;
		philo_thinking(philo);
		state = philo_get_state(philo, philo->print_mutex);
		usleep(1);
	}
	return (NULL);
}

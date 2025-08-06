/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/08/06 20:51:11 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printed_mutex(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_right);
	printed_mutex(philo, "has taken a fork");
	pthread_mutex_lock(philo->print_mutex);
	philo->last_time_meal = get_time();
	pthread_mutex_unlock(philo->print_mutex);
	printed_mutex(philo, "is eating");
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

int	philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (left_fork(philo))
			return (EXIT_FAILURE);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		printed_mutex(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_left);
		printed_mutex(philo, "has taken a fork");
		pthread_mutex_lock(philo->print_mutex);
		philo->last_time_meal = get_time();
		pthread_mutex_unlock(philo->print_mutex);
		printed_mutex(philo, "is eating");
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
	printed_mutex(philo, "is sleeping");
	if (forced_usleep(philo->time_sleep, philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	philo_thinking(t_philo *philo)
{
	printed_mutex(philo, "is thinking");
	if (forced_usleep(1, philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}	

void	*philo_routine(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!simulation_stopped(philo->table, philo->stop_mutex))
	{
		if (is_dead(philo) || philo->is_full == 1)
			return (NULL);
		if (simulation_stopped(philo->table, philo->stop_mutex)
			|| philo_eating(philo))
			return (NULL);
		if (philo->table->size_philos_eat > 0)
			philos_full(philo);
		if (simulation_stopped(philo->table, philo->stop_mutex)
			|| philo->is_full == 1 || philo_sleep(philo))
			return (NULL);
		if (simulation_stopped(philo->table, philo->stop_mutex)
			|| philo_thinking(philo))
			return (NULL);
	}
	return (NULL);
}

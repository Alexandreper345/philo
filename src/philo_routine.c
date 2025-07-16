/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/15 21:07:28 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_eating(t_table *table)
{
	int	i;
	t_table *current;
	int	id;
	i = 1;
	
	id = table->philos->id;
	while (i <= table->count_philos)
	{
		if (table->forks == 1)
		{
			table->philos->id = id;
			(table)->forks--;
			printf("o id {%d} pegou outro garfo\n",table->philos->id);
			table->size_philos_eat += 1;
			if (table->size_philos_eat == table->count_philos)
				return ;
			table->forks += 2;
			id++;
		}
		(table)->forks--;
		printf("o id {%d} pegou o garfo\n",table->philos->id);
		i++;
	}
	
}

void	philo_sleep(void)
{
	printf("SLEEP\n");
}

void	*philo_routine(void	*ptr)
{
	t_table	*table;
	
	table = (t_table *)ptr;
	if (table->count_philos > 1)
		philo_eating(table);
	else
		philo_sleep();		
}
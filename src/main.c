/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:01:30 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/17 21:28:41 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
 
static int	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc  > 6)
		return (EXIT_FAILURE);
	else if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (EXIT_FAILURE);
	while (argv[++i])
	{
		if (isnumeric(argv[i]))
			return (EXIT_FAILURE);
		else if ((i >= 2 && i <= 4) && ft_atoi(argv[i]) < 60)
			return (EXIT_FAILURE);
		else if (i == 5 && ft_atoi(argv[i]) < 1)
			return (EXIT_FAILURE);	
	}
	return (EXIT_SUCCESS);
}

static t_philo *init_philos(t_table *table, int i, t_mtx *array)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = i + 1;
	philo->status = THINKING;
	philo->time_die = table->time_die;
	philo->time_eat = table->time_eat;
	philo->time_sleep = table->time_sleep;

	philo->fork_left = array[i];
	if (i == 0)
		philo->fork_right = array[table->count_philos - 1];
	else
		philo->fork_right = array[i - 1];
	pthread_create(&philo->id_thread, NULL, &philo_routine, (void *)philo);
	return (philo);
}	

int	main(int argc, char **argv)
{
	t_table	*table;
	t_mtx	*array;
	int		i;	

	i = -1;
	if (validate_args(argc, argv))
		return (EXIT_FAILURE);
	table = init_table(&table, argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	array = create_array_mutex(table);
	while (++i < table->count_philos)
		table->philos[i] = init_philos(table, i, array);
	i = -1;
	while (++i < table->count_philos)
		pthread_join(table->philos[i]->id_thread, NULL);
	return (0);
}

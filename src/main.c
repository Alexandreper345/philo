/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:01:30 by alda-sil          #+#    #+#             */
/*   Updated: 2025/08/06 21:00:08 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
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

void	clean(t_table *table, t_mtx *array)
{
	int	i;

	i = -1;
	while (++i < table->count_philos)
		pthread_mutex_destroy(&array[i]);
	pthread_mutex_destroy(&table->dead_philo);
	pthread_mutex_destroy(&table->stop_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	i = -1;
	while (++i < table->count_philos)
		free(table->philos[i]);
	free(table->philos);
	free(table);
	free(array);
}

int	main(int argc, char **argv)
{
	t_table		*table;
	t_mtx		*array;
	int			i;
	pthread_t	monitor;

	i = -1;
	if (validate_args(argc, argv))
		return (EXIT_FAILURE);
	table = init_table(&table, argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	array = create_array_mutex(table);
	while (++i < table->count_philos)
		table->philos[i] = init_philos(table, i, array);
	pthread_create(&monitor, NULL, monitor_routine, (void *)table);
	i = -1;
	while (++i < table->count_philos)
		pthread_join(table->philos[i]->id_thread, NULL);
	pthread_join(monitor, NULL);
	clean(table, array);
	return (0);
}

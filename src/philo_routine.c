/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/07 22:07:42 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_eating(int argc, char **argv)
{

	int	*forks;
	int	i;
	int	j;

	i = 0;
	forks = 0;
	forks = ft_range(*forks, ft_atoi(argv[1]));

	while (forks[i])
	{
		printf("%d", i);
		i++;
	}
	
	while (j < ft_atoi(argv[1]))
	{
		if (forks[i])
		{
			printf("pegou um garfo\n");
			if (forks[(i + 1) % ft_atoi(argv[1])] == 0)
			{
				printf("pegou outro garfo\n");
				forks[(i + 1) % ft_atoi(argv[1])] = 1;
			}
			forks[i] = 1;	
		}
		while (forks[i] == 1)
			i++;
		j++;
	}	
}

void	philo_sleep(int argc, char **argv)
{
	printf("dormindo\n");
}
int	philo_routine(int argc, char **argv)
{
	if (ft_atoi(argv[1]) > 1)
		philo_eating(argc, argv);
	else
		philo_sleep(argc, argv);
	return (0);
		
}
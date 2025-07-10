/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:59:31 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/10 17:32:25 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_eating(int argc, char **argv)
{
	int	*forks;
	int	i;
	int	flag;

	i = 0;
	forks = 0;
	flag = 0;
	forks = ft_range(forks, ft_atoi(argv[1]));
	
	while (i <= ft_atoi(argv[1]))
	{
		if (forks[i] && flag == 0)
		{
			printf("pegou um garfo: {%d}\n", forks[i]);
			if (forks[(i + 1)])
			{
				printf("pegou outro garfo: {%d} \n",forks[i + 1]);
				forks[(i + 1)] = 1;
			}
			else if (forks[i] == 0 && forks[(i + 1) % ft_atoi(argv[1])] == 0)
			{
				printf("pegou outro garfo: {%d} \n", forks[(i + 1) % ft_atoi(argv[1])]);
				forks[(i + 1) % ft_atoi(argv[1])] = 1;
			}
			forks[i] = 1;
			flag = 1;
		}
		else
			printf("thinking...\n");
		i++;
	}	
}

void	philo_sleep(int argc, char **argv)
{
	printf("SLEEP\n");
}
int	philo_routine(int argc, char **argv)
{
	if (ft_atoi(argv[1]) > 1)
		philo_eating(argc, argv);
	else
		philo_sleep(argc, argv);
	return (0);
		
}
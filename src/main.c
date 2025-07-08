/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:01:30 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/07 21:51:26 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	isnumeric(char *value)
{
	int	i;
	
	i = -1;
	while (value[++i])
	{
		if (!ft_isdigit(value[i]))
			return(1);	
	}
	return (0);
}
 
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

int	main(int argc, char **argv)
{
	//t_table	**table;
	
	if (validate_args(argc, argv))
		return (EXIT_FAILURE);
	else if (philo_routine(argc, argv))
		return (EXIT_FAILURE);

	return (0);
}
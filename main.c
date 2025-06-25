/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:01:30 by alda-sil          #+#    #+#             */
/*   Updated: 2025/06/24 21:00:56 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	isnumeric(char *value)
{
	int	i;
	
	i = -1;
	while (value[++i])
	{
		printf("entrou %c\n", value[i]);
		if (ft_isdigit(value[i]))
			return(0);
	}
	printf("oi\n");
	return (1);
}
static int	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("[ERROR]: arguments number invalid\n");
		return (EXIT_FAILURE);
	}
	else if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		printf("[ERROR]: first argument invalid\n");
		return (EXIT_FAILURE);
	}	
	while (argv[++i])
	{
		printf("pre\n");
		if (isnumeric(argv[i]))
		{
			printf("pos\n");
			printf("%s\n", argv[i]);
			printf("[ERROR]: argument invalid\n");
			return (EXIT_FAILURE);
		}	
		else if ((i >= 2 && i <= 4) && ft_atoi(argv[i]) < 60)
		{
			printf("[ERROR]: timestap invalid\n");
			return (EXIT_FAILURE);
		}	
		else if (i == 6 && ft_atoi(argv[i]) < 1)
		{
			printf("[ERROR]: Invalid sixth argument\n");
			return (EXIT_FAILURE);
		}	
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	//t_table	*table;
	
	if (validate_args(argc, argv))
		return (EXIT_FAILURE);
	//else if (init_table(table, argc, argv))
	//	return (EXIT_FAILURE);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:53:39 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/15 21:16:58 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	temp;

	i = 0;
	signal = 1;
	temp = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal *= -1;
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp = temp * 10 + (nptr[i] - '0');
		i++;
	}
	return (signal * temp);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:53:39 by alda-sil          #+#    #+#             */
/*   Updated: 2025/07/07 20:54:06 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	*ft_range(int start, int end)
{
	int	*range;
	int	i;
	int	size;
	int	step;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);

	i = 0;
	step = 1;
	if (start > end)
		step = -1;

	while (start != end)
	{
		range[i++] = start;
		start += step;
	}
	range[i] = start;
	return (range);
}

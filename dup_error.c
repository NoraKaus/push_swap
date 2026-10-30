/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:30:49 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 10:41:29 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if dup, 1 if all good
int	check_dup(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// handle the case that len == 0 || len == 1, BEFORE this function is called
float	calc_disorder(int *array, int len)
{
	int	total;
	int	mistakes;
	int	i;
	int	j;

	total = 0;
	mistakes = 0;
	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] > array[j])
				mistakes++;
			j++;
			total++;
		}
		i++;
	}
	return ((float)(mistakes) / (float)(total));
}

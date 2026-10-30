/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:07:47 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 16:14:33 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_rank(int *array, int len, int n)
{
	int	rank;
	int	i;

	rank = 0;
	i = 0;
	while (i < len)
	{
		if (array[i] < n)
			rank++;
		i++;
	}
	return (rank);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:55:30 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/30 17:39:50 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_arr(char **nums, ssize_t len, ssize_t **nbrs)
{
	ssize_t	i;

	*nbrs = malloc(len * sizeof(int));
	if (!nbrs)
		return (0);
	i = 0;
	while (nums[i])
	{
		nbrs[i] = atoi_lng(nums[i]);
		if (!&nbrs[i])
			return (0);
		if (nbrs[i] < INT_MIN || nbrs[i] > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

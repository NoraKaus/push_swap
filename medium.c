/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:53:04 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/02 14:01:19 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	k_sort(t_input *input, t_env *env, t_ops *ops)
{
	int	i;
	int	k;

	i = 0;
	k = ft_sqrt(196 * input->len) / 10;
	
}

int	ft_sqrt(long nb)
{
	long	start;
	long	end;
	long	mid;

	start = 0;
	end = nb;

	if (nb < 0)
		return (0);
	while (start <= end)
	{
		mid = (start + (end - start) / 2);
		if (mid * mid == nb)
			return ((int)mid);
		if (mid * mid > nb)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return ((int)end);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(98000));
}

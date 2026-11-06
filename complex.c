/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:19:46 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 17:34:19 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex(t_env *env, t_ops *ops)
{
	int	size;
	int	i;
	int	max_bits;
	int	k;

	size = ft_int_lstsize(env->st_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	k = 0;
	while (k < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((env->st_a->rank) >> k) & 1) == 0)
				pb(&(env->st_a), &(env->st_b), ops);
			else
				ra(&(env->st_a), ops);
			i++;
		}
		while (env->st_b != 0)
			pa(&(env->st_a), &(env->st_b), ops);
		k++;
	}
}

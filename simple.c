/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:44:54 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/02 14:19:26 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void simple(t_env *env, t_ops *ops)
{
	int	i;
	int size;

	i = 0;
	size = ft_int_lstsize(env->st_a);
	while (i < size)
	{
		while (env->st_a->rank != i)
			ra(&(env->st_a), ops);
		pb(&(env->st_a), &(env->st_b), ops);
		i++;
	}
	while (env->st_b != 0)
		pa(&(env->st_a), &(env->st_b), ops);
}

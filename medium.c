/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:53:04 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/03 11:45:22 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_sqrt(long nb);
static int	find_pos(t_int_list *list, int i);
static void	sort_to_b(t_input *input, t_env *env, t_ops *ops);
static void	sort_to_a(t_env *env, t_ops *ops, int i);

void	k_sort(t_input *input, t_env *env, t_ops *ops)
{
	sort_to_b(input, env, ops);
	sort_to_a(env, ops, (input->len - 1));
}

static void	sort_to_b(t_input *input, t_env *env, t_ops *ops)
{
	int	k;
	int	i;

	i = 0;
	k = ft_sqrt(196 * input->len) / 10;
	while (env->st_a != NULL)
	{
		if ((env->st_a->rank) <= (k + i))
		{
			pb(&(env->st_a), &(env->st_b), ops);
			if ((env->st_b->rank) <= i)
				rb(&(env->st_b), ops);
			i++;
		}
		else
			ra(&(env->st_a), ops);
	}
}

static void	sort_to_a(t_env *env, t_ops *ops, int i)
{
	int	index;

	while (env->st_b != NULL)
	{
		index = find_pos(env->st_b, i);
		if (index == 0)
		{
			pa(&(env->st_a), &(env->st_b), ops);
			i--;
		}
		else if (index < (i / 2))
			rb(&(env->st_b), ops);
		else
			rrb(&(env->st_b), ops);
	}
}

static int	find_pos(t_int_list *list, int i)
{
	int	count;

	count = 0;
	while (list)
	{
		if (list->rank == i)
			return (count);
		count++;
		list = list->next;
	}
	return (count);
}

static int	ft_sqrt(long nb)
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

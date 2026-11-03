/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:14:07 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/03 10:55:30 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_env *env, t_ops *ops);
static int	find_pos(t_int_list *list, int i);
static void	push_smallest(t_env *env, t_ops *ops, int size);

int	sort(t_input *input, t_env *env, t_ops *ops)
{
	int	size;

	size = input->len;
	if (input->len == 2)
		sa(&(env->st_a), ops);
	else if (input->len == 3)
		three_sort(env, ops);
	else
	{
		push_smallest(env, ops, size);
		three_sort(env, ops);
		while (env->st_b)
			pa(&(env->st_a), &(env->st_b), ops);
	}
	return (1);
}

static void	three_sort(t_env *env, t_ops *ops)
{
	if (env->st_a->rank > env->st_a->next->rank
		&& env->st_a->rank > env->st_a->next->next->rank)
		ra(&(env->st_a), ops);
	else if (env->st_a->next->rank > env->st_a->next->next->rank
		&& env->st_a->next->rank > env->st_a->rank)
		rra(&(env->st_a), ops);
	if (env->st_a->rank > env->st_a->next->rank)
		sa(&(env->st_a), ops);
}

static void	push_smallest(t_env *env, t_ops *ops, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (size > 3)
	{
		count = find_pos(env->st_a, i);
		if (count <= size / 2)
		{
			if (count == 1)
				sa(&(env->st_a), ops);
			while (env->st_a->rank != i)
				ra(&(env->st_a), ops);
		}
		else
		{
			while (env->st_a->rank != i)
				rra(&(env->st_a), ops);
		}
		pb(&(env->st_a), &(env->st_b), ops);
		i++;
		size--;
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

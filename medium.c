/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:53:04 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/02 16:27:51 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_sqrt(long nb);

static void	init_structs(t_input *input, t_ops *ops, t_env *env)
{
	init_select(input);
	init_ops(ops);
	init_env(env);
}

void	k_sort(t_input *input, t_env *env, t_ops *ops)
{
	int	i;
	int	k;

	i = 0;
	k = ft_sqrt(196 * input->len) / 10;
	while (env->st_a != NULL)
	{
		if (env->st_a->rank <= i)
		{
			pb(&(env->st_a), &(env->st_b), ops);
			rb(&(env->st_b), ops);
			i++;
		}
		else if (env->st_a->rank <= (k + i))
		{
			pb(&(env->st_a), &(env->st_b), ops);
			i++;
		}
		else
			ra(&(env->st_a), ops);
	}
	i--;
	while (env->st_b != NULL)
	{
		if (env->st_b->rank == i)
		{
			pa(&(env->st_a), &(env->st_b), ops);
			i--;
		}
		else if (env->st_b->rank < i)
			rrb(&(env->st_b), ops);
		else
			rb(&(env->st_b), ops);
	}
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
	t_input		input;
	t_ops		ops;
	t_env		env;
	int			check;
	int array[12] = {1, 3, 9, 4, 0, 2, 7, 6, -24, -156, 156, 789};

	init_structs(&input, &ops, &env);
	input.len = 12;
	check = build_stack(array, 12, &(env.st_a));
	if (!check)
		return (0);
	k_sort(&input, &env, &ops);
	printf("\n%d\n", ops.total);
	while (env.st_a)
	{
		printf("%d ", env.st_a->content);
		env.st_a = env.st_a->next;
	}
	ft_int_lstclear(&(env.st_a));

}

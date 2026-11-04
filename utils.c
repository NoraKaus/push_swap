/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:50:06 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/04 16:45:39 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//initialise the selector struct
void	init_select(t_input *input)
{
	input->bench = 0;
	input->strategy = 0;
	input->len = 0;
	input->array = NULL;
	input->disorder = 0.00;
}

void	init_env(t_env *env)
{
	env->st_a = NULL;
	env->st_b = NULL;
}

void	init_ops(t_ops *ops)
{
	ops->total = 0;
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->print = 1;
}

//convert string to number (return long for INT_MIN & INT_MAX lengths)
long	atoi_lng(const char *nptr, int *k)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
	while (nptr[*k] == ' ' || (nptr[*k] >= '\f' && nptr[*k] <= '\r'))
		(*k)++;
	if (nptr[*k] == '-' || nptr[*k] == '+')
	{
		if (nptr[*k] == '-')
			sign = -1;
		(*k)++;
	}
	while (nptr[*k] >= '0' && nptr[*k] <= '9')
	{
		n = (n * 10) + (nptr[*k] - '0');
		if (n > 2147483648)
			return (n);
		(*k)++;
	}
	return (n * sign);
}

void	init_structs(t_input *input, t_ops *ops, t_env *env)
{
	init_select(input);
	init_ops(ops);
	init_env(env);
}

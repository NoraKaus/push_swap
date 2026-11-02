/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:14:07 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/02 18:22:40 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_input *input, t_env *env, t_ops *ops)
{
	if (input->len == 1)
		return (1);
	if (input->len == 2)
	{
		sa(env->st_a, ops);
		return (1);
	}
	if (input->len == 3)
	{
		if (env->st_a->rank == 2)
			ra(env->st_a, ops);
		else if (env->st_a->rank == 1)
			
	}
}
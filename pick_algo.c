/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:56:36 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/03 16:36:50 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_adaptive(t_input *input, t_ops *ops, t_env *env);

void	pick_algo(t_input *input, t_ops *ops, t_env *env)
{
	if (input->len < 6)
		sort(input, env, ops);
	else if (input->strategy == SIMPLE)
		simple(env, ops);
	else if (input->strategy == MEDIUM)
		k_sort(input, env, ops);
	else if (input->strategy == COMPLEX)
		complex(env, ops);
	else
		run_adaptive(input, ops, env);
}

static void	run_adaptive(t_input *input, t_ops *ops, t_env *env)
{
	if (input->disorder < 0.2)
		simple(env, ops);
	else if (input->disorder < 0.5)
		k_sort(input, env, ops);
	else
		complex(env, ops);
}

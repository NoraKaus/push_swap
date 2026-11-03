/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:56:28 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/03 12:43:30 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bench(int is_bench, t_input *input, t_ops *ops)
{
	if (is_bench == 0)
		return ;
	ft_printf(2, "[bench] disorder: %f%%\n", input->disorder);
	print_strategy(input);
	ft_printf(2, "[bench] total_ops: %i\n", ops->total);
	ft_printf(2, "[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n",
		ops->sa, ops->sb, ops->ss, ops->pa, ops->pb);
	ft_printf(2, "[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n",
	ops->ra, ops->rb, ops->rr, ops->rra, ops->rrb, ops->rrr);
}

void print_strategy(t_input *input)
{
	if (input->strategy == SIMPLE)
		ft_printf(2, "[bench] strategy: Simple / O(n²)\n");
	else if (input->strategy == MEDIUM)
		ft_printf(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (input->strategy == COMPLEX)
		ft_printf(2, "[bench] strategy: Complex / O(n log n)\n");
	else
	{
		ft_printf(2, "[bench] strategy: Adaptive / ");
		if (input->disorder < 0.2)
			ft_printf(2, "O(n²)\n");
		else if (input->disorder < 0.5)
			ft_printf(2, "O(n√n)\n");
		else
			ft_printf(2, "O(n log n)\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:01:03 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/02 11:04:59 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_int_list **stack)
{
	t_int_list	*temp;

	if (ft_int_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	ft_int_lstadd_back(stack, temp);
}

void	ra(t_int_list **stack, t_ops *ops)
{
	rotate(stack);
	(ops->ra)++;
	(ops->total)++;
	write(1, "ra\n", 3);
}

void	rb(t_int_list **stack, t_ops *ops)
{
	rotate(stack);
	(ops->rb)++;
	(ops->total)++;
	write(1, "rb\n", 3);
}

void	rr(t_int_list **stack_a, t_int_list **stack_b, t_ops *ops)
{
	rotate(stack_a);
	rotate(stack_b);
	(ops->rr)++;
	(ops->total)++;
	write(1, "rr\n", 3);
}

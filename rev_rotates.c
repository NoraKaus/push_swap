/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:21:39 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 12:35:23 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_int_list **stack)
{
	t_int_list	*temp;
	t_int_list	*current;

	if (ft_int_lstsize(*stack) < 2)
		return ;
	temp = ft_int_lstlast(*stack);
	current = *stack;
	while (current->next != temp)
	{
		current = current->next;
	}
	current->next = 0;
	ft_int_lstadd_front(stack, temp);
}

void	rra(t_int_list **stack, t_ops *ops)
{
	rev_rotate(stack);
	(ops->rra)++;
	(ops->total)++;
	if (ops->print)
		write(1, "rra\n", 4);
}

void	rrb(t_int_list **stack, t_ops *ops)
{
	rev_rotate(stack);
	(ops->rrb)++;
	(ops->total)++;
	if (ops->print)
		write(1, "rrb\n", 4);
}

void	rrr(t_int_list **stack_a, t_int_list **stack_b, t_ops *ops)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	(ops->rrr)++;
	(ops->total)++;
	if (ops->print)
		write(1, "rrr\n", 4);
}

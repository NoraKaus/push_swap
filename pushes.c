/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:29:58 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 12:59:39 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_int_list **stack1, t_int_list **stack2)
{
	t_int_list	*temp;

	if (*stack2 == 0)
		return ;
	temp = (*stack2)->next;
	ft_int_lstadd_front(stack1, *stack2);
	*stack2 = temp;
}

void pa(t_int_list **stack_a, t_int_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void pb(t_int_list **stack_a, t_int_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
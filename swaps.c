/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:39:56 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 12:02:46 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_int_list **stack)
{
	t_int_list *temp;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void sa(t_int_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void sb(t_int_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void ss(t_int_list **stack_a, t_int_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
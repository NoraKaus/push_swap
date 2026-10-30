/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:21:39 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 17:29:45 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_int_list **stack)
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

void	rra(t_int_list **stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 3);
}

void	rrb(t_int_list **stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 3);
}

void	rrr(t_int_list **stack_a, t_int_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rra\n", 3);
}

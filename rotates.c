/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:01:03 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 13:19:54 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_int_list **stack)
{
	t_int_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	ft_int_lstadd_back(stack, temp);
}

void	ra(t_int_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_int_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_int_list **stack_a, t_int_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:21:39 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 13:31:42 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate(t_int_list **stack)
{
	t_int_list	*temp;
	t_int_list	*current;

	temp = ft_int_lstlast(*stack);
	current = *stack;
	while (current->next != temp)
	{
		current = current->next;
	}
	current->next = 0;
	ft_int_lstadd_front(stack, temp);
}
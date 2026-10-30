/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:01:03 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 13:05:40 by ezaimaki         ###   ########.fr       */
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
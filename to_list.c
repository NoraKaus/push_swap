/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:07:47 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 17:27:27 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_rank(int *array, int len, int n)
{
	int	rank;
	int	i;

	rank = 0;
	i = 0;
	while (i < len)
	{
		if (array[i] < n)
			rank++;
		i++;
	}
	return (rank);
}

// returns 0 if failure to malloc, 1 if all good
int	build_stack(int *array, int len, t_int_list **start)
{
	int	i;
	t_int_list	*new;

	i = 0;
	while (i < len)
	{
		new = ft_int_lstnew(array[i], find_rank(array, len, array[i]));
		if (new == 0)
		{
			ft_int_lstclear(start);
			return (0);
		}
		ft_int_lstadd_back(start, new);
		i++;
	}
	return (1);
}

void ft_int_lstclear(t_int_list **start)
{
	t_list	*current;
	t_list	*next_one;

	if (start == 0 || *start == 0)
		return ;
	current = *start;
	next_one = current->next;
	while (next_one != 0)
	{
		free(current)
		current = next_one;
		next_one = current->next;
	}
	free(current);
	*start = 0;
}
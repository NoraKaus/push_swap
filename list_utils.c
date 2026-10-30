/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:53:53 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/30 17:45:04 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_lstsize(t_int_list *lst)
{
	int			count;
	t_int_list	*current;

	if (lst == 0)
		return (0);
	count = 1;
	current = lst;
	while (current->next != 0)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_int_list	*ft_int_lstnew(int content)
{
	t_int_list	*new;

	new = malloc(sizeof(t_int_list));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

void	ft_int_lstadd_front(t_int_list **lst, t_int_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_int_lstadd_back(t_int_list **lst, t_int_list *new)
{
	t_int_list	*current;

	current = *lst;
	if (current == 0)
	{
		*lst = new;
		return ;
	}
	while (current->next != 0)
		current = current->next;
	current->next = new;
	new->next = 0;
}

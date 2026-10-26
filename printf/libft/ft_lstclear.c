/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:31:33 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/13 19:04:36 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_one;

	if (lst == 0 || *lst == 0)
		return ;
	current = *lst;
	next_one = current->next;
	while (next_one != 0)
	{
		ft_lstdelone(current, del);
		current = next_one;
		next_one = current->next;
	}
	ft_lstdelone(current, del);
	*lst = 0;
}

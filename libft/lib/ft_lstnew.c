/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:54:38 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/12 19:49:43 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *new1 = ft_lstnew("A");
// 	t_list *new2 = ft_lstnew("B");
// 	t_list *new3 = ft_lstnew("C");
// 	t_list *new4 = ft_lstnew("D");
// 	t_list **start = &new1;
// 	ft_lstadd_front(start, new2);
// 	ft_lstadd_front(start, new3);
// 	ft_lstadd_front(start, new4);
// 	printf("Size: %i\n", ft_lstsize(*start));
// 	t_list *current = *start;
// 	while(current->next != 0)
// 	{
// 		printf("%p\n", current);
// 		printf("%s\n", (char *)current->content);
// 		printf("%p\n\n", current->next);
// 		current = current->next;
// 	}
// 	printf("%p\n", current);
// 	printf("%s\n", (char *)current->content);
// 	printf("%p\n\n", current->next);
// }
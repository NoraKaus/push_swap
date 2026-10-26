/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:41:55 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/26 18:10:52 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_handling(int argc, char **argv)
{
	ssize_t		i;
	ssize_t		j;
	t_selector	*select;
	char		**compare;
	char		**values;
	if (argc < 2)
	{
		ft_printf("Error\n");
		exit (EXIT_FAILURE);
	}
	i = 0;
	compare = {"--simple", "--medium", "--complex", "--adaptive" };
	
	memset(&select, 0, sizeof(t_selector));
	if (strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
	{
		select->bench = 1;
		i++;
	}
	j = 0;
	while (compare[j])
	{
		if (strncmp(argv[i], compare[j], ft_strlen(argv[i])) == 0)
		{
			
		}
	}

}

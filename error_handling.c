/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:41:55 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/26 16:46:36 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_handling(int argc, char **argv)
{
	ssize_t		i;
	t_selector	*select;

	if (argc < 2)
	{
		ft_printf("Error\n");
		exit (EXIT_FAILURE);
	}
	i = 0;
	if (strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
	{
		select->bench = 1;
		i++;
	}
	else
	{
		
	}

}

void init_struct()
{
	
}


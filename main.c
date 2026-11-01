/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:20:49 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/01 20:23:40 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			err;
	int			i;
	t_input		input;

	init_select(&input);
	err = error_handling(argc, argv, &input);
	if (err < 1)
	{
		write(2, "Error\n", 6);
		free (input.array);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < input.len)
	{
		ft_printf("%d ", input.array[i]);
		i++;
	}
	free (input.array);
	write(1, "\nSuccess\n", 9);
	exit(EXIT_SUCCESS);
}
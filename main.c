/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:20:49 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/01 20:53:46 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			err;
	t_input		input;

	init_select(&input);
	err = error_handling(argc, argv, &input);
	if (err == -1)
		exit(EXIT_FAILURE);
	if (err == 0)
	{
		write(2, "Error\n", 6);
		free (input.array);
		exit(EXIT_FAILURE);
	}
	if (calc_disorder(input.array, input.len) == 0)
	{
		free (input.array);
		exit(EXIT_SUCCESS);
	}
	free (input.array);
	write(1, "\nSuccess\n", 9);
	exit(EXIT_SUCCESS);
}
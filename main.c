/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:20:49 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/02 11:04:10 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			err;
	t_input		input;
	t_ops		ops;

	init_select(&input);
	init_ops(&ops);
	err = error_handling(argc, argv, &input);
	if (err == -1)
		exit(EXIT_FAILURE);
	if (err == 0)
	{
		write(2, "Error\n", 6);
		free (input.array);
		exit(EXIT_FAILURE);
	}
	input.disorder = calc_disorder(input.array, input.len);
	if (input.disorder == 0)
	{
		free (input.array);
		exit(EXIT_SUCCESS);
	}
	free (input.array);
	exit(EXIT_SUCCESS);
}
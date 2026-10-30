/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:20:49 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/30 17:46:03 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			err;
	ssize_t		**nbrs;
	t_selector	select;

	err = error_handling(argc, argv, &select, nbrs);
	if (err < 1)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	write(2, "Success\n", 9);
	exit(EXIT_SUCCESS);
}
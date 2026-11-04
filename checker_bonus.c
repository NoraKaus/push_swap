/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:36:54 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 13:54:11 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	handle_err(int argc, char **argv, t_input *input);

int main (int argc, char **argv)
{
	t_input		input;
	t_ops		ops;
	t_env		env;

	init_structs(&input, &ops, &env);
	ops.print = 0;
	handle_err(argc, argv, &input);
	if (build_stack(input.array, input.len, &(env.st_a)) == 0)
	{
		free (input.array);
		exit(EXIT_FAILURE);
	}
	//rest of logic
	ft_int_lstclear(&(env.st_a));
	free (input.array);
	exit(EXIT_SUCCESS);
}

static void	handle_err(int argc, char **argv, t_input *input)
{
	int	err;

	err = bonus_error_handling(argc, argv, input);
	if (err == -1)
		exit(EXIT_FAILURE);
	if (err == 0)
	{
		write(2, "Error\n", 6);
		free (input->array);
		exit(EXIT_FAILURE);
	}
}


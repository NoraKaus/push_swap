/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:20:49 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/03 13:01:25 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_structs(t_input *input, t_ops *ops, t_env *env);
static int	handle_err(int argc, char **argv, t_input *input, t_env *env);

int	main(int argc, char **argv)
{
	int			err;
	t_input		input;
	t_ops		ops;
	t_env		env;

	init_structs(&input, &ops, &env);
	err = handle_err(argc, argv, &input, &env);
	if (err == 0)
		exit(EXIT_FAILURE);
	pick_algo(&input, &ops, &env);
	bench(input.bench, &input, &ops);
	ft_int_lstclear(&(env.st_a));
	free (input.array);
	exit(EXIT_SUCCESS);
}

static void	init_structs(t_input *input, t_ops *ops, t_env *env)
{
	init_select(input);
	init_ops(ops);
	init_env(env);
}

static int	handle_err(int argc, char **argv, t_input *input, t_env *env)
{
	int	err;

	err = error_handling(argc, argv, input);
	if (err == -1)
		exit(EXIT_FAILURE);
	if (err == 0)
	{
		write(2, "Error\n", 6);
		free (input->array);
		exit(EXIT_FAILURE);
	}
	input->disorder = calc_disorder(input->array, input->len);
	if (input->disorder == 0)
	{
		bench(input->bench, input, ops);
		free (input->array);
		exit(EXIT_SUCCESS);
	}
	if (build_stack(input->array, input->len, &(env->st_a)) == 0)
	{
		free (input->array);
		exit(EXIT_FAILURE);
	}
	return (1);
}

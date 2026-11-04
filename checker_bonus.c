/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:36:54 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 14:14:33 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	handle_err(int argc, char **argv, t_input *input);
static void	check_output(t_env *env);

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

static void	check_output(t_env *env)
{
	int	i;
	int	len;
	t_int_list *current;

	i = 0;
	if (env->st_b != 0)
	{
		ft_int_lstclear(&(env.st_b));
		write(1, "KO\n", 3);
		return ;
	}
	len = ft_int_lstsize(env->st_a);
	current = env->st_a;
	while (i < len)
	{
		if (current->rank != i)
		{
			write(1, "KO\n", 3);
			return ;
		}
		current = current->next;
		i++;
	}
	write(1, "OK\n", 3);
}


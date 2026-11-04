/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:17:12 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 15:56:38 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_do_move(t_env *env, t_ops *ops, char *str);

//returns 0 if error in instructions
int	read_lines(t_env *env, t_ops *ops)
{
	char	*line;

	line = get_next_line(0);
	while (line != 0)
	{
		if (check_do_move(env, ops, line) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}


// static int	check_inst(char *str)
// {
// 	if (ft_strncmp(str, "sa\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "sb\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "ss\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "pa\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "pb\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "ra\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "rb\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "rr\n", 3) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "rra\n", 4) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "rrb\n", 4) == 0)
// 		return (1);
// 	else if (ft_strncmp(str, "rrr\n", 4) == 0)
// 		return (1);
// 	else
// 		return (0);
// }

//returns 0 if instruction doesn't match any of the moves
static int	check_do_move(t_env *env, t_ops *ops, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(&(env->st_a), ops);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(&(env->st_b), ops);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(&(env->st_a), &(env->st_b), ops);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(&(env->st_a), &(env->st_b), ops);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(&(env->st_a), &(env->st_b), ops);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(&(env->st_a), ops);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(&(env->st_b), ops);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(&(env->st_a), &(env->st_b), ops);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(&(env->st_a), ops);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(&(env->st_b), ops);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(&(env->st_a), &(env->st_b), ops);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:18:16 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/30 11:54:20 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

enum	e_strategy
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
};

typedef struct s_int_list
{
	int content;
	int rank;
	struct s_int_list *next;
}	t_int_list;

typedef struct s_selector
{
	int	bench;
	int	strategy;
}	t_selector;

int		error_handling(int argc, char **argv);
void	init_select(t_selector *select);

#endif

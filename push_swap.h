/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:18:16 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/30 17:50:28 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "printf/ft_printf.h"
# include "printf/libft/libft.h"
// give startegies values from 1 to 4
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
	int					content;
	int					rank;
	struct s_int_list	*next;
}						t_int_list;

// holds the strategy for algorithms
typedef struct s_selector
{
	int	bench;
	int	strategy;
}	t_selector;

void	init_select(t_selector *select);
ssize_t	input_len(char **str);
ssize_t	atoi_lng(const char *nptr);
int		build_arr(char **nums, ssize_t len, ssize_t **nbrs);
int		error_handling(int argc, char **argv, t_selector *select, int **nbrs);

#endif

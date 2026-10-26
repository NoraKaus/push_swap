/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:18:16 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/26 18:10:03 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

# define B "bench"
# define S "simple"
# define M "medium"
# define C "complex"
# define A "adaptive"

typedef struct s_selector
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}	t_selector;

#endif

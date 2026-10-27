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

enum strategy{
	NONE, SIMPLE, MEDIUM, COMPLEX, ADAPTIVE
};

typedef struct s_selector
{
	int	bench;
	int	strategy;
}	t_selector;

int	error_handling(int argc, char **argv);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

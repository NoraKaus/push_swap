/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:18:16 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/02 13:14:52 by ekausiny         ###   ########.fr       */
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

// holds the strategy for algorithms and int array
typedef struct s_input
{
	int		bench;
	int		strategy;
	int		len;
	int		*array;
	float	disorder;
}	t_input;

typedef struct s_ops
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_env
{
	struct s_int_list	*st_a;
	struct s_int_list	*st_b;
}	t_env;

void		init_select(t_input *select);
long		atoi_lng(const char *nptr, int *k);
int			build_arr(char **argv, t_input *input, int i);
int			error_handling(int argc, char **argv, t_input *input);
int			check_dup(int *array, int len);
float		calc_disorder(int *array, int len);
int			ft_int_lstsize(t_int_list *lst);
t_int_list	*ft_int_lstnew(int content, int rank);
t_int_list	*ft_int_lstlast(t_int_list *lst);
void		ft_int_lstadd_front(t_int_list **lst, t_int_list *new);
void		ft_int_lstadd_back(t_int_list **lst, t_int_list *new);
void		ft_int_lstclear(t_int_list **start);
int			build_stack(int *array, int len, t_int_list **start);
int			find_rank(int *array, int len, int n);
void		sa(t_int_list **stack, t_ops *ops);
void		sb(t_int_list **stack, t_ops *ops);
void		ss(t_int_list **stack_a, t_int_list **stack_b, t_ops *ops);
void		pa(t_int_list **stack_a, t_int_list **stack_b, t_ops *ops);
void		pb(t_int_list **stack_a, t_int_list **stack_b, t_ops *ops);
void		ra(t_int_list **stack, t_ops *ops);
void		rb(t_int_list **stack, t_ops *ops);
void		rr(t_int_list **stack_a, t_int_list **stack_b, t_ops *ops);
void		rra(t_int_list **stack, t_ops *ops);
void		rrb(t_int_list **stack, t_ops *ops);
void		rrr(t_int_list **stack_a, t_int_list **stack_b, t_ops *ops);

#endif

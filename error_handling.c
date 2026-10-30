/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:41:55 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/30 17:44:43 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		chk_strategy(char **argv, t_selector *select, ssize_t *i);
static ssize_t	find_match(char *argv);
static ssize_t	validate(char **argv, ssize_t i);
static ssize_t	chk_conv(int argc, char **argv, int i, char	**nums);

// inits the select struct, inputs values for strategy,
// inputs and builds array
int	error_handling(int argc, char **argv, t_selector *select, int **nbrs)
{
	ssize_t		i;
	ssize_t		vld_len;
	int			chk;
	char		**nums;

	if (argc < 2)
		exit (EXIT_FAILURE);
	i = 1;
	init_select(select);
	chk_strategy(argv, select, &i);
	vld_len = chck_conv(argc, argv, i);
	if (!vld_len)
		return (0);
	chk = build_arr(nums, vld_len, nbrs);
	if (!chk)
		return (0);
	return (1);
}

// checks if inp is nums, fills the num array,returns the length of input)
static ssize_t	chk_conv(int argc, char **argv, int i, char	**nums)
{
	ssize_t		valid;
	ssize_t		ls_len;

	ls_len = argc - i;
	while (i < argc)
	{
		valid = validate(argv, i);
		if (!valid)
			return (0);
		i++;
	}
	if (ls_len == 1)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums)
			return (0);
		ls_len = input_len(nums);
	}
	else
		nums = &argv[argc - ls_len];
	return (ls_len);
}

//inputs the strategy and bench if any given
static void	chk_strategy(char **argv, t_selector *select, ssize_t *i)
{
	ssize_t	is_match;

	while (argv[*i])
	{
		is_match = find_match(argv[*i]);
		if (is_match > 0 && !select->strategy)
		{
			select->strategy = is_match;
			(*i)++;
		}
		else if (ft_strncmp(argv[*i], "--bench", 8) == 0 && !select->bench)
		{
			select->bench = 1;
			(*i)++;
		}
		else
			break ;
	}
	if (!select->strategy)
		select->strategy = ADAPTIVE;
}

//matches the strategy selector and adjusts the flag
static ssize_t	find_match(char *argv)
{
	if (ft_strncmp(argv, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(argv, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(argv, "--complex", 10) == 0)
		return (COMPLEX);
	if (ft_strncmp(argv, "--adaptive", 11) == 0)
		return (ADAPTIVE);
	return (0);
}

//checks if input is numbers, ' ' and '-' '+' only
static ssize_t	validate(char **argv, ssize_t i)
{
	ssize_t	k;

	k = 0;
	if (argv[i][0] == '\0')
		return (0);
	while (argv[i][k])
	{
		if ((argv[i][k] == '-' || argv[i][k] == '+')
			&& !ft_isdigit(argv[i][k + 1]))
			return (0);
		if (argv[i][k] == '-' || argv[i][k] == '+')
			k++;
		if (!ft_isdigit(argv[i][k]))
			return (0);
		while (ft_isdigit(argv[i][k]) && argv[i][k] != '\0')
			k++;
		if (argv[i][k] == '\0')
			break ;
		if (argv[i][k] != ' ')
			return (0);
		while (argv[i][k] == ' ')
			k++;
	}
	return (1);
}

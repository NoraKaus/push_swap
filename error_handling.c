/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:41:55 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/01 20:33:53 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chk_strategy(char **argv, t_input *input, int *i);
static int	find_match(char *argv);
static int	validate(char **argv, int i);
static int	chk_conv(int argc, char **argv, int i);

// inits the*input struct, inputs values for strategy,
// inputs and builds array
int	error_handling(int argc, char **argv, t_input *input)
{
	int	i;
	int	chk;

	i = 1;
	chk_strategy(argv, input, &i);
	if (i == argc)
		exit (EXIT_FAILURE);
	input->len = chk_conv(argc, argv, i);
	if (input->len == 0)
		return (0);
	chk = build_arr(argv, input, i);
	if (!chk)
		return (0);
	chk = check_dup(input->array, input->len);
	if (!chk)
		return (0);
	return (1);
}

// checks if inp is nums, returns the length of input)
static int	chk_conv(int argc, char **argv, int i)
{
	int	valid;
	int	total;

	total = 0;
	while (i < argc)
	{
		valid = validate(argv, i);
		if (!valid)
			return (0);
		i++;
		total += valid;
	}
	return (total);
}

//inputs the strategy and bench if any given
static void	chk_strategy(char **argv, t_input *input, int *i)
{
	int	is_match;

	while (argv[*i])
	{
		is_match = find_match(argv[*i]);
		if (is_match > 0 && !input->strategy)
		{
			input->strategy = is_match;
			(*i)++;
		}
		else if (ft_strncmp(argv[*i], "--bench", 8) == 0 && !input->bench)
		{
			input->bench = 1;
			(*i)++;
		}
		else
			break ;
	}
	if (!input->strategy)
		input->strategy = ADAPTIVE;
}

//matches the strategy selector and adjusts the flag
static int	find_match(char *argv)
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
static int	validate(char **argv, int i)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (argv[i][k])
	{
		while (argv[i][k] == ' ')
			k++;
		if (argv[i][k] == '\0')
			return (count);
		if (argv[i][k] == '-' || argv[i][k] == '+')
			k++;
		if (!ft_isdigit(argv[i][k]))
			return (0);
		while (ft_isdigit(argv[i][k]))
			k++;
		count++;
		if (argv[i][k] != ' ' && argv[i][k] != '\0')
			return (0);
	}
	return (count);
}

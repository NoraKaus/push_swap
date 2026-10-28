/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:41:55 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/28 18:56:01 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		chk_strategy(char **argv, t_selector *select, ssize_t *i);
static ssize_t	find_match(char *argv);
static ssize_t	single_input(char **argv, ssize_t i);
static ssize_t	multi_input(char **argv, ssize_t i);

int	error_handling(int argc, char **argv)
{
	t_selector	select;
	ssize_t		i;
	ssize_t		valid;

	if (argc < 2)
		exit (EXIT_FAILURE);
	i = 1;
	init_select(&select);
	chk_strategy(argv, &select, &i);
	if (i + 1 == argc)
		valid = single_input(argv, i);
	else
		valid = multi_input(argv, i);
	if (!valid)
		return (0);
	return (1);
}

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

static ssize_t	single_input(char **argv, ssize_t i)
{
	ssize_t	k;

	k = 0;
	while (argv[i][k])
	{
		if (argv[i][k] == '-' && !ft_isdigit(argv[i][k + 1]))
			return (0);
		if (argv[i][k] == '-')
			k++;
		while (ft_isdigit(argv[i][k]) && argv[i][k] != '\0')
			k++;
		if (argv[i][k] == '\0')
			break ;
		if (argv[i][k] != ' ')
			return (0);
		k++;
	}
	return (1);
}

static ssize_t	multi_input(char **argv, ssize_t i)
{
	ssize_t	k;

	k = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
			k++;
		while (argv[i][k])
		{
			if (!ft_isdigit(argv[i][k]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

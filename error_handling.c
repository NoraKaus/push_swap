/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:41:55 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/26 18:10:52 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_handling(int argc, char **argv)
{
	t_selector	select;
	ssize_t		i;

	if (argc < 2)
		exit (EXIT_FAILURE);
	i = 1;
	init_select(&select);
	chk_strategy(argv, &select, &i);

}

void init_select(t_selector *select)
{
	select->bench = 0;
	select->strategy = 0;
}

void chk_strategy(char **argv, t_selector *select, ssize_t *i)
{
	ssize_t is_match;

	while (argv[*i])
	{
		is_match = find_match(argv[*i], select);
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
			break;
	}
	if (!select->strategy)
		select->strategy = ADAPTIVE;
}	

ssize_t find_match(char *argv, t_selector *select)
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

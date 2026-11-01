/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:55:30 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/01 19:39:16 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_arr(char **argv, t_input *input, int i)
{
	int		j;
	int		k;
	long	check;

	input->array = malloc(input->len * sizeof(int));
	if (!(input->array))
		return (0);
	j = 0;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			check = atoi_lng(argv[i], &k);
			if (check < INT_MIN || check > INT_MAX)
				return (0);
			input->array[j] = (int)check;
			while (argv[i][k] == ' ')
				k++;
			j++;
		}
		i++;
	}
	return (1);
}

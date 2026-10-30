/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:50:06 by ekausiny          #+#    #+#             */
/*   Updated: 2026/10/30 17:40:14 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//initialise the selector struct
void	init_select(t_selector *select)
{
	select->bench = 0;
	select->strategy = 0;
}

//calculate the number of entries in the input
ssize_t	input_len(char **str)
{
	ssize_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

//convert string to number (return long for INT_MIN & INT_MAX lengths)
ssize_t	atoi_lng(const char *nptr)
{
	int		i;
	ssize_t	n;
	int		sign;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\f' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

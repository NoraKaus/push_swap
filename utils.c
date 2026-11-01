/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:50:06 by ekausiny          #+#    #+#             */
/*   Updated: 2026/11/01 19:39:48 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//initialise the selector struct
void	init_select(t_input *input)
{
	input->bench = 0;
	input->strategy = 0;
	input->len = 0;
	input->array = NULL;
}

//convert string to number (return long for INT_MIN & INT_MAX lengths)
long	atoi_lng(const char *nptr, int *k)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
	while (nptr[*k] == ' ' || (nptr[*k] >= '\f' && nptr[*k] <= '\r'))
		(*k)++;
	if (nptr[*k] == '-' || nptr[*k] == '+')
	{
		if (nptr[*k] == '-')
			sign = -1;
		(*k)++;
	}
	while (nptr[*k] >= '0' && nptr[*k] <= '9')
	{
		n = (n * 10) + (nptr[*k] - '0');
		if (n > 2147483648)
			return (n);
		(*k)++;
	}
	return (n * sign);
}

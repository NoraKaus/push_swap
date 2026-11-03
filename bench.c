/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:56:28 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/03 11:17:52 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bench(int is_bench, t_input *input, t_ops *ops)
{
	if (is_bench == 0)
		return ;
	ft_printf(2, "[bench] disorder: %f%%");
}
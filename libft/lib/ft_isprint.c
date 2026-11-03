/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:54:30 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:27:28 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main(void)
// {
//     printf("%i\n", ft_isprint(' '));
//     printf("%i\n", ft_isprint('i'));
//     printf("%i\n", ft_isprint('.'));
//     printf("%i\n", ft_isprint('\n'));
// }
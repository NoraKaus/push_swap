/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:39:37 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/15 13:13:02 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main (void)
// {
// 	printf("%i\n", ft_isalnum('F'));
// 	printf("%i\n", ft_isalnum('a'));
// 	printf("%i\n", ft_isalnum('Z'));
// 	printf("%i\n", ft_isalnum('9'));
// 	printf("%i\n", ft_isalnum('!'));
// }
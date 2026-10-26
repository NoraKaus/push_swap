/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:53:02 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:27:09 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
// 	printf("%i\n", ft_isalpha('F'));
// 	printf("%i\n", ft_isalpha('f'));
// 	printf("%i\n", ft_isalpha('a'));
//     printf("%i\n", ft_isalpha('Z'));
//     printf("%i\n", ft_isalpha('-'));
// }

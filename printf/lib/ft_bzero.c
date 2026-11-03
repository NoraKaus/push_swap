/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:54:33 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:26:53 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*dest = 0;
		i++;
		dest++;
	}
}

// int main(void)
// {
// 	char str[] = "hello";
// 	ft_bzero(str, 5);
// 	printf("%s", str);
// }
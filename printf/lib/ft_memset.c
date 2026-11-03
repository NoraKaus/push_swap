/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:15:37 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:31:52 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	cast;
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)s;
	i = 0;
	cast = (unsigned char) c;
	while (i < n)
	{
		*dest = cast;
		dest++;
		i++;
	}
	return (s);
}

// int main(void)
// {
// 	char str[] = "hello";
// 	char *result = ft_memset(str, 55, 5);
// 	printf("%s", result);
// }
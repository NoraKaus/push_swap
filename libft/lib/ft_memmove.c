/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:50:57 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/14 14:42:00 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			temp_dest[i] = temp_src[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}

// int main(void)
// {
// 	char src[] = "abcDEFGHijk";
// 	ft_memmove(&src[3], src, 5);
// 	printf("%s", src);
// }

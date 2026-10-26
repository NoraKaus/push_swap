/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:12:41 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:31:45 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*temp_dest = *temp_src;
		i++;
		temp_dest++;
		temp_src++;
	}
	return (dest);
}

// int main(void)
// {
// 	char dest[] = "hello";
// 	char src[] = "world";
// 	ft_memcpy(dest, src, 5);
// 	printf("%s", dest);
// }

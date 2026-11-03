/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:31:31 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/14 14:22:04 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (unsigned char) c)
			return (&temp[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char *str = ft_memchr("hello world", 'o', 8);
// 	printf("%s", str);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:25:13 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 15:45:21 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	size_t			i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size > (SIZE_MAX / nmemb))
		return (0);
	array = malloc(nmemb * size);
	if (array == 0)
		return (0);
	while (i < nmemb * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

// int main(void)
// {
// 	// char *str = ft_calloc(6, 4);
// 	printf("%p\n", ft_calloc(0, 4));
// 	printf("%p\n", calloc(0, 4));

// }
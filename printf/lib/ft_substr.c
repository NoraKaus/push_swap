/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:56:04 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/14 16:51:56 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	leftover_size;
	char	*sub;

	if (start < ft_strlen(s))
	{
		leftover_size = ft_strlen(s) - start;
		if (len > leftover_size)
			len = leftover_size;
	}
	else
		len = 0;
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_substr("abcdefg", 2, 15));
// }

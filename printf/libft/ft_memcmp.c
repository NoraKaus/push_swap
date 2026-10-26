/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 10:38:02 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:31:41 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

static int	ft_compare_chars(unsigned char c1, unsigned char c2);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (ft_compare_chars(str1[i], str2[i]) != 0)
		{
			return (ft_compare_chars(str1[i], str2[i]));
		}
		i++;
	}
	return (0);
}

static int	ft_compare_chars(unsigned char c1, unsigned char c2)
{
	if (c1 == c2)
		return (0);
	else
		return (c1 - c2);
}

// int	main(void)
// {
//     const char *s1 = "ABCD";
//     const char *s2 = "ABEI";
//     size_t n = 3;
// 	printf("%i\n", ft_memcmp(s1, s2, n));
// 	printf("%i\n", memcmp(s1, s2, n));
// }
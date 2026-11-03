/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:02:02 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:46:29 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <bsd/string.h>
// #include <stdio.h>
#include "libft.h"

static size_t	ft_strlen_help(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_help(src);
	if (!(size > 0))
		return (len);
	while (i <= len)
	{
		if (i == size - 1)
		{
			dst[i] = '\0';
			break ;
		}
		else
		{
			dst[i] = src[i];
		}
		i++;
	}
	return (len);
}

static size_t	ft_strlen_help(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// int main(void)
// {
// 	char src1[] = "aBcDeFgHi";
// 	char dest1[] = "!!!!!!!!";
// 	char src2[] = "aBcDeFgHi";
// 	char dest2[] = "!!!!!!!!";
// 	ft_strlcpy(dest1, src1, 5);
// 	strlcpy(dest2, src2, 5);
// 	printf("%s\n", dest1);
// 	printf("%s\n", dest2);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:51:44 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:29:00 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
// #include <stdio.h>
#include "libft.h"

static size_t	ft_src_strlen(const char *s);
static size_t	ft_dst_strlen(char *s, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	len_dst = ft_dst_strlen(dst, size);
	if (size == 0)
		return (ft_src_strlen(src));
	if (size == len_dst)
		return (size + ft_src_strlen(src));
	i = 0;
	while (len_dst + i < size - 1 && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_src_strlen(src));
}

static size_t	ft_src_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_dst_strlen(char *s, size_t size)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && len < size)
		len++;
	return (len);
}

// int main(void)
// {
// 	char dst[10] = "hello";
// 	char src[] = "hi";
// 	size_t total = ft_strlcat(dst, src, 9);
// 	printf("%s\n", dst);
// 	printf("%zu\n", total);

// 	char dst2[10] = "hello";
// 	char src2[] = "hi";
// 	size_t total2 = strlcat(dst2, src2, 9);
// 	printf("%s\n", dst2);
// 	printf("%zu\n", total2);
// }
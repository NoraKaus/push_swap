/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:12:20 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:46:57 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

static int		ft_compare_chars(unsigned char c1, unsigned char c2);
static size_t	ft_strlen_help(const char *s);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len1;

	i = 0;
	len1 = ft_strlen_help(s1);
	while (i < n && i <= len1)
	{
		if (!(ft_compare_chars(s1[i], s2[i]) == 0))
		{
			return (ft_compare_chars(s1[i], s2[i]));
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

static size_t	ft_strlen_help(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// int	main(void)
// {
//     const char *s1 = "ABCI";
//     const char *s2 = "ABEI";
//     size_t n = 5;
// 	printf("%i\n", ft_strncmp(s1, s2, n));
// 	printf("%i\n", strncmp(s1, s2, n));
// }
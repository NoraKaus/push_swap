/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:00:54 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 13:48:06 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
// #include <stdio.h>
#include "libft.h"

static size_t	ft_strlen_help(const char *s);
static int		ft_is_phrase(char *str, char *find, size_t i, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen_help(little) == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			if (ft_is_phrase((char *)big, (char *)little, i, len) == 1)
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

static size_t	ft_strlen_help(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	ft_is_phrase(char *str, char *find, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (find[j] != '\0')
	{
		if (!(str[i + j] == find[j]) || (i + j) == len)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

// int	main(void)
// {
// 	char *big = "AAAcAAccAAccc";
// 	char *little = "cc";
// 	printf("%s\n", ft_strnstr(big, little, 9));
// 	printf("%s\n", strnstr(big, little, 9));
// }
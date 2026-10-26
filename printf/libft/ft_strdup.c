/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:49:41 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/08 16:00:53 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

static size_t	ft_strlen_help(const char *s);

char	*ft_strdup(const char *s)
{
	size_t		len;
	size_t		i;
	char		*new_str;

	len = ft_strlen_help(s);
	new_str = (char *)malloc(len + 1);
	if (new_str == 0)
		return (0);
	i = 0;
	while (i <= len)
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
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
// 	const char *s = "hello";
// 	char *new = ft_strdup(s);
// 	char *test = strdup(s);
// 	printf("%s\n%s", new, test);
// }
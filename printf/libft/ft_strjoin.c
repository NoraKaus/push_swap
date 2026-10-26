/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:52:47 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/12 11:31:34 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i;
	char	*result;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_len + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (*s1 != '\0')
	{
		result[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		result[i] = *s2;
		s2++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_strjoin("Hello", "World"));
// }

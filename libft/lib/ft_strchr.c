/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:52:54 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/14 14:50:10 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (0);
}

// int main(void)
// {
// 	printf("%s", ft_strchr("abcdecf", 'c'));
// }
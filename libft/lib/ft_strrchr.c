/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:02:42 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/14 16:11:50 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
		{
			ptr = (char *) &s[i];
		}
		i++;
	}
	if (s[i] == (unsigned char) c)
	{
		ptr = (char *) &s[i];
	}
	return (ptr);
}

// int main(void)
// {
// 	printf("%s", ft_strrchr("abcdecf", 'c'));
// }
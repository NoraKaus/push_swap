/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:54:56 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/12 14:00:40 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = malloc(ft_strlen(s) + 1);
	if (new == 0)
		return (0);
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

// static char ft_modify(unsigned int i, char c)
// {
// 	c = 'b';
// 	return (c);
// }

// #include <stdio.h>
// int main(void)
// {
// 	char *str = ft_strmapi("abcde", ft_modify);
// 	printf("%s\n", str);
// }
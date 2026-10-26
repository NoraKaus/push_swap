/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:45:06 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/14 16:40:02 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// static void ft_mod(unsigned int i, char *str)
// {
// 	str[i] = 'b';
// }

// #include <stdio.h>
// int main(void)
// {
// 	char s13[] = "aaa";
// 	ft_striteri(s13, ft_mod);
// 	printf("%s\n", s13);
// }
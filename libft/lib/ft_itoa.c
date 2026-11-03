/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:43:45 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/12 12:51:03 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n);
static char	*ft_fill_buffer(char *str, int n, int len);

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = (char *)malloc (12);
		if (str == 0)
			return (0);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = (char *)malloc (ft_int_len(n) + 1);
	if (str == 0)
		return (0);
	ft_fill_buffer(str, n, ft_int_len(n));
	return (str);
}

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

static char	*ft_fill_buffer(char *str, int n, int len)
{
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		while (len >= 1)
		{
			str[len] = (n % 10) + 48;
			n /= 10;
			len--;
		}
	}
	else
	{
		while (len >= 0)
		{
			str[len] = (n % 10) + 48;
			n /= 10;
			len--;
		}
	}
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = ft_itoa(2147);
// 	printf("%s\n", str);
// 	free(str);
// }
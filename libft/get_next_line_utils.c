/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:14:52 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 12:44:50 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// returns position if \n found or -1 if not found
int	ft_find_n(char	*str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//return 0 in failure, 1 in success
int	ft_split_n(char *to_split, int position, char **left, char **right)
{
	*left = ft_substr(to_split, 0, position + 1);
	if (*left == 0)
	{
		*right = 0;
		return (0);
	}
	*right = ft_substr(to_split, position + 1, ft_strlen(to_split)
			- position - 1);
	if (*right == 0)
	{
		free(*left);
		*left = 0;
		return (0);
	}
	return (1);
}

int	ft_strlen_line(const char *s)
{
	int	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr_line(char const *s, int start, int len)
{
	int		i;
	char	*sub;

	if (s == 0 || len < 0)
		return (0);
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin_line(char const *s1, char const *s2)
{
	int		i;
	char	*result;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (s1 != 0 && *s1 != '\0')
	{
		result[i] = *s1;
		s1++;
		i++;
	}
	while (s2 != 0 && *s2 != '\0')
	{
		result[i] = *s2;
		s2++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

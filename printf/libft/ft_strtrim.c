/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:32:46 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/14 19:10:48 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_in_set(char const *set, const char c);
static size_t	ft_calc_size(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	size;
	size_t	start;
	size_t	i;

	size = ft_calc_size(s1, set);
	result = malloc (size + 1);
	if (result == 0)
		return (0);
	start = 0;
	while (s1[start] != '\0' && ft_is_in_set(set, s1[start]) == 1)
		start++;
	i = 0;
	while (i < size)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static size_t	ft_calc_size(char const *s1, char const *set)
{
	size_t	char_ammount;
	size_t	i;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (0);
	char_ammount = 0;
	i = 0;
	while (i < s1_len && ft_is_in_set(set, s1[i]) == 1)
		i++;
	char_ammount += i;
	if (char_ammount == s1_len)
		return (s1_len - char_ammount);
	i = s1_len - 1;
	while (i > 0 && ft_is_in_set(set, s1[i]) == 1)
	{
		char_ammount++;
		i--;
	}
	return (s1_len - char_ammount);
}

// return 1 if char in the set, 0 if not
static int	ft_is_in_set(char const *set, const char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_strtrim("aaaBBaaBccc", "ac"));
// }
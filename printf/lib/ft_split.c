/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:12:43 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/12 11:46:03 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c);
static int	ft_mem(char **array, int pos, int size);
static char	*ft_copy(char *dest, const char *src, int start, int i);
static int	ft_array_creation(char **array, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)malloc (sizeof(char *) * (ft_word_count(s, c) + 1));
	if (array == 0)
		return (0);
	if (ft_array_creation(array, s, c) == 0)
		return (0);
	return (array);
}

// returns 1 in success, 0 if allocation failed
static int	ft_array_creation(char **array, char const *s, char c)
{
	int	i;
	int	pos;
	int	start;

	i = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (ft_mem(array, pos, (i - start)) == 0)
			return (0);
		ft_copy(array[pos], s, start, i);
		pos++;
	}
	array[pos] = 0;
	return (1);
}

// returns 1 in successful allocation, 0 if not + frees
static int	ft_mem(char **array, int pos, int size)
{
	array[pos] = malloc((size) + 1);
	if (array[pos] == 0)
	{
		while (pos >= 0)
		{
			free(array[pos]);
			pos--;
		}
		free(array);
		return (0);
	}
	return (1);
}

static char	*ft_copy(char *dest, const char *src, int start, int i)
{
	int	j;

	j = 0;
	while (start < i)
	{
		dest[j] = src[start];
		start++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static int	ft_word_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			return (count);
		while (s[i] != '\0' && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	char **array = ft_split("ccAAcAAAcccAAAAcAAAAA", 'c');
// 	int i = 0;
// 	while (array[i] != 0)
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// 	while (i >= 0)
// 	{
// 		free(array[i]);
// 		i--;
// 	}
// 	free(array);
// }
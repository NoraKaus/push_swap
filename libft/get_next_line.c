/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:38:04 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 12:44:38 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	char		*new;
	int			size;

	new = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (ft_check_leftover(&leftover, &new) == 1)
		return (new);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == 0)
	{
		free(leftover);
		leftover = 0;
		return (0);
	}
	size = ft_while_no_n(fd, buffer, &new, &leftover);
	if (size == -2 || ft_end(size, buffer, &new, &leftover) == 0)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	return (new);
}

int	ft_check_leftover(char **leftover, char **new)
{
	char	*sub_leftover;
	int		position;

	if (*leftover != 0 && ft_strlen(*leftover) != 0)
	{
		position = ft_find_n(*leftover, ft_strlen(*leftover));
		if (position != -1)
		{
			ft_split_n(*leftover, position, new, &sub_leftover);
			free(*leftover);
			*leftover = sub_leftover;
			return (1);
		}
	}
	return (0);
}

//returns -2 if malloc error
int	ft_while_no_n(int fd, char *buffer, char **new, char **leftover)
{
	int	size;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size > 0)
		buffer[size] = '\0';
	while (size > 0 && ft_find_n(buffer, size) == -1)
	{
		*new = ft_strjoin(*leftover, buffer);
		free(*leftover);
		*leftover = *new;
		if (*leftover == 0)
			return (-2);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size >= 0)
			buffer[size] = '\0';
	}
	return (size);
}

// 0 in case of error
int	ft_end(int size, char *buffer, char **new, char **leftover)
{
	if (size == -1)
	{
		free(*leftover);
		*leftover = NULL;
		return (0);
	}
	else if (size == 0)
	{
		if (*leftover != 0 && ft_strlen(*leftover) != 0)
			*new = ft_strjoin(*leftover, 0);
		free(*leftover);
		*leftover = NULL;
	}
	else
		*new = ft_sep_buffer(leftover, buffer, ft_find_n(buffer, size));
	return (1);
}

char	*ft_sep_buffer(char **leftover, char *buffer, int position)
{
	char	*sub_left;
	char	*sub_right;
	char	*new;

	if (ft_split_n(buffer, position, &sub_left, &sub_right) == 0)
	{
		free(*leftover);
		*leftover = NULL;
		return (0);
	}
	new = ft_strjoin(*leftover, sub_left);
	free(sub_left);
	free(*leftover);
	*leftover = 0;
	if (new == 0)
	{
		free(sub_right);
		return (0);
	}
	*leftover = sub_right;
	return (new);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *str = get_next_line(fd);
// 	while (str != 0)
// 	{
// 		printf("[%s]", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// 	// int fd = 0;
// 	// char *str = get_next_line(fd);
// 	// while (str != 0)
// 	// {
// 	// 	printf("[%s]", str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);
// 	// }
// }

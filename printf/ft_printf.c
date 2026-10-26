/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:22:06 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/21 18:43:03 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	if (format == 0)
		return (-1);
	va_start(args, format);
	total = ft_print_output(args, format);
	va_end(args);
	return (total);
}

int	ft_print_output(va_list args, const char *format)
{
	int	i;
	int	total;
	int	check;

	i = 0;
	total = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i], 1);
			i++;
			total++;
		}
		if (format[i] == '\0')
			break ;
		check = ft_choose(args, format[i + 1]);
		if (check == -1)
			return (-1);
		total += check;
		i += 2;
	}
	return (total);
}

// #include <stdio.h>
// #include <assert.h>
// #include <limits.h>
// int main(void)
// {
// 	assert(ft_printf("h\n") == printf("h\n"));

// 	assert(ft_printf("\n") == printf("\n"));

// 	assert(ft_printf("hello\n") == printf("hello\n"));

// 	assert(ft_printf("hello, %c\n", 'g') == printf("hello, %c\n", 'g'));

// 	assert(ft_printf("hello, %s\n", "world") == printf("hello, %s\n", "world"));

// 	char *str = "hello";
// 	assert(ft_printf("hello, %p\n", str) == printf("hello, %p\n", str));

// 	assert(ft_printf("hello, %d\n", INT_MIN) == printf("hello, %d\n", INT_MIN));

// 	assert(ft_printf("hello, %i\n", -123) == printf("hello, %i\n", -123));

// 	assert(ft_printf("hello, %u\n", 123) == printf("hello, %u\n", 123));

// 	assert(ft_printf("hello, %x\n", 123) == printf("hello, %x\n", 123));

// 	assert(ft_printf("hello, %X\n", 123) == printf("hello, %X\n", 123));

// 	assert(ft_printf("hello, %%\n") == printf("hello, %%\n"));

// 	assert(ft_printf("hello, %X, %s\n", 123, "worlds") == 
// 	printf("hello, %X, %s\n", 123, "worlds"));

// 	printf("TEST ERROR: \n");
// 	ft_printf("hello, %w\n", 123);
// 	// printf("hello, %w\n", 123);
// }
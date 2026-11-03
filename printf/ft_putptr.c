/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:18:47 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/03 11:54:31 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(uintptr_t p, char *base, int *len);

int	ft_putptr_mod(uintptr_t p)
{
	int	len;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	ft_putptr(p, "0123456789abcdef", &len);
	return (len);
}

static void	ft_putptr(uintptr_t p, char *base, int *len)
{
	if (p < 16)
	{
		write(1, &base[p], 1);
		(*len)++;
	}
	else
	{
		ft_putptr(p / 16, base, len);
		write(1, &base[p % 16], 1);
		(*len)++;
	}
}

int ft_putfl_mod(double fl, int fd)
{
	int	len;
	int temp;

	len = 0;
	temp = (int)(fl * 10000);
	len += ft_putnbr_fd_mod(temp / 100, fd);
	write(fd, ".", 1);
	len++;
	if (temp  % 100 < 10)
	{
		write(fd, "0", 1);
		len++;
	}
	len += ft_putnbr_fd_mod(temp % 100, fd);
	return (len);
}
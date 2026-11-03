/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:49:07 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/20 15:23:42 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_uns_base(unsigned int n, char *base,
				unsigned int b_len, int *len);

int	ft_putchar_fd_mod(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd_mod(char *s, int fd)
{
	if (s == 0)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return ((int) ft_strlen(s));
}

int	ft_putnbr_fd_mod(int n, int fd)
{
	int	len;

	ft_putnbr_fd(n, fd);
	if (n == -2147483648)
		return (11);
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

int	ft_putnbr_uns_base_mod(unsigned int n, char *base)
{
	int	len;

	len = 0;
	ft_putnbr_uns_base(n, base, (unsigned int) ft_strlen(base), &len);
	return (len);
}

static void	ft_putnbr_uns_base(unsigned int n, char *base,
unsigned int b_len, int *len)
{
	if (n < b_len)
	{
		write(1, &base[n], 1);
		(*len)++;
	}
	else
	{
		ft_putnbr_uns_base(n / b_len, base, b_len, len);
		write(1, &base[n % b_len], 1);
		(*len)++;
	}
}

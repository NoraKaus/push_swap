/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:34:37 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/10/20 15:08:33 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//returns ammount of chars printed
int	ft_choose(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd_mod(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd_mod(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putptr_mod((uintptr_t) va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_mod(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_uns_base_mod(va_arg(args, unsigned int),
				"0123456789"));
	else if (c == 'x')
		return (ft_putnbr_uns_base_mod(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_uns_base_mod(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (write(1, &c, 1));
	else
		return (-1);
}

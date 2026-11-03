/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:39:25 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/03 16:07:35 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "lib/libft.h"

int	ft_printf(int fd, const char *format, ...);
int	ft_print_output(va_list args, const char *format, int fd);
int	ft_count_args(const char *format);
int	ft_is_in_set(char c);
int	ft_choose(va_list args, char c, int fd);
int	ft_putchar_fd_mod(char c, int fd);
int	ft_putstr_fd_mod(char *s, int fd);
int	ft_putnbr_fd_mod(int n, int fd);
int	ft_putnbr_uns_base_mod(unsigned int n, char *base);
int	ft_putptr_mod(uintptr_t p);
int	ft_putfl_mod(double fl, int fd);

#endif
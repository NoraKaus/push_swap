/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:39:25 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/03 12:46:39 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

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
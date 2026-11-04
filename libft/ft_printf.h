/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:39:25 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 12:43:53 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "lib/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_printf(int fd, const char *format, ...);
int		ft_print_output(va_list args, const char *format, int fd);
int		ft_count_args(const char *format);
int		ft_is_in_set(char c);
int		ft_choose(va_list args, char c, int fd);
int		ft_putchar_fd_mod(char c, int fd);
int		ft_putstr_fd_mod(char *s, int fd);
int		ft_putnbr_fd_mod(int n, int fd);
int		ft_putnbr_uns_base_mod(unsigned int n, char *base);
int		ft_putptr_mod(uintptr_t p);
int		ft_putfl_mod(double fl, int fd);
char	*get_next_line(int fd);
int		ft_end(int size, char *buffer, char **new, char **leftover);
char	*ft_sep_buffer(char **leftover, char *buffer, int position);
int		ft_check_leftover(char **leftover, char **new);
int		ft_find_n(char	*str, int size);
int		ft_strlen_line(const char *s);
char	*ft_substr_line(char const *s, int start, int len);
char	*ft_strjoin_line(char const *s1, char const *s2);
int		ft_split_n(char *to_split, int position, char **left, char **right);
int		ft_while_no_n(int fd, char *buffer, char **new, char **leftover);

#endif
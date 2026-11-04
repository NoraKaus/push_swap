/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:51:42 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 12:40:47 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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

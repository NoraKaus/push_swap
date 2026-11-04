/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezaimaki <ezaimaki@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:37:30 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 15:16:19 by ezaimaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
#include "push_swap.h"

int	bonus_error_handling(int argc, char **argv, t_input *input);
int	read_lines(t_env *env, t_ops *ops);

#endif
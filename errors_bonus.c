/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekausiny <ekausiny@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:47:52 by ezaimaki          #+#    #+#             */
/*   Updated: 2026/11/04 15:48:34 by ekausiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	validate(char **argv, int i);
static int	chk_conv(int argc, char **argv, int i);

int	bonus_error_handling(int argc, char **argv, t_input *input)
{
	int	i;
	int	chk;

	i = 1;
	if (i == argc)
		return (-1);
	input->len = chk_conv(argc, argv, i);
	if (input->len == 0)
		return (0);
	chk = build_arr(argv, input, i);
	if (!chk)
		return (0);
	chk = check_dup(input->array, input->len);
	if (!chk)
		return (0);
	return (1);
}

// checks if inp is nums, returns the length of input)
static int	chk_conv(int argc, char **argv, int i)
{
	int	valid;
	int	total;

	total = 0;
	while (i < argc)
	{
		valid = validate(argv, i);
		if (!valid)
			return (0);
		i++;
		total += valid;
	}
	return (total);
}

//checks if input is numbers, ' ' and '-' '+' only
static int	validate(char **argv, int i)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (argv[i][k])
	{
		while (argv[i][k] == ' ')
			k++;
		if (argv[i][k] == '\0')
			return (count);
		if (argv[i][k] == '-' || argv[i][k] == '+')
			k++;
		if (!ft_isdigit(argv[i][k]))
			return (0);
		while (ft_isdigit(argv[i][k]))
			k++;
		count++;
		if (argv[i][k] != ' ' && argv[i][k] != '\0')
			return (0);
	}
	return (count);
}
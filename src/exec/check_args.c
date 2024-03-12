/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/12 23:13:13 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sign(char c)
{
	return (c == '-' || c == '+');
}

static bool	is_space(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		return (false);
	return (true);
}

static bool	is_only_digit(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1])
		i++;
	else if (is_space(&str[i]) && str[i + 1])
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (false);
	return (true);
}

static bool	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (j != i && (nb_strcmp(argv[i], argv[j]) == 0))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	global_check_successful(char **argv)
{
	int	i;
	int	nb_zeros;

	i = 0;
	nb_zeros = 0;
	while (argv[i])
	{
		if (!is_only_digit(argv[i]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (false);
		}
		nb_zeros += have_zeros(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (false);
	}
	if (have_duplicates(argv) == true)
		return (write(STDERR_FILENO, "Error\n", 6), false);
	return (true);
}

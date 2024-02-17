/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:57:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/16 21:13:37 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	have_zeros(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (false);
	return (true);
}

int	nb_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

void	check_doubles(t_stack *a, int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*debut;

	tmp = a;
	while (tmp->next)
	{
		debut = tmp->next;
		while (debut)
		{
			if (debut->content == tmp->content)
				exit_error_stack(&a, NULL, argc, argv);
			debut = debut->next;
		}
		tmp = tmp->next;
	}
}

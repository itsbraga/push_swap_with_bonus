/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:49:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*convert_n_fill_stack(int argc, char **argv)
{
	t_stack		*a;
	int			i;
	long		nbr;

	a = NULL;
	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (nbr >= INT_MIN && nbr <= INT_MAX)
		{
			if (i == 0)
				a = stack_new((int)nbr);
			else
				add2bottom(&a, stack_new((int)nbr));
		}
		else
			exit_error_stack(&a, NULL, argc, argv);
		i++;
	}
	return (a);
}

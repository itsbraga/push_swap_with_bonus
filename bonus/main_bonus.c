/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:03:26 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/15 03:28:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (line)
	{
		line = get_next_line(0);
		if (do_op(a, b, line) == EXIT_SUCCESS)
		{
			free(line);
			return ;
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		(argv++);
	if (!global_check_successful(argv))
		return (free_split(argc, argv), EXIT_FAILURE);
	a = convert_n_fill_stack(argc, argv);
	if (!a)
		exit_error_stack(&a, NULL, argc, argv);
	b = NULL;
	checker(&a, &b);
	if (is_sorted(a) && b == NULL)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	(clear_stack(&a), clear_stack(&b));
	free_split(argc, argv);
	return (EXIT_SUCCESS);
}
